var videoElement = document.querySelector('video');

/*
var canvas = document.getElementById('pcCanvas');
var ctx = canvas.getContext('2d');
*/
var mobileCanvas = document.getElementById('mobileCanvas');
var mobileCtx = mobileCanvas.getContext('2d');
var videoSelect = document.querySelector('select#videoSource');
var videoOption = document.getElementById('videoOption');
var buttonGo = document.getElementById('go');
var barcode_result = document.getElementById('dbr');

var isPaused = false;
var videoWidth = 640,
  videoHeight = 480;
var mobileVideoWidth = 240,
  mobileVideoHeight = 320;

var ZXing = null;
var decodePtr = null;
var Module = {
  onRuntimeInitialized: function () {
    ZXing = Module;
    decodePtr = ZXing.Runtime.addFunction(decodeCallback);
  }
};

var decodeCallback = function (ptr, len, resultIndex, resultCount) {
  var result = new Uint8Array(ZXing.HEAPU8.buffer, ptr, len);
  console.log(String.fromCharCode.apply(null, result));
  barcode_result.textContent = String.fromCharCode.apply(null, result);
  buttonGo.disabled = false;
    mobileCanvas.style.display = 'block';

};

// stackoverflow: http://stackoverflow.com/questions/4998908/convert-data-uri-to-file-then-append-to-formdata/5100158
function dataURItoBlob(dataURI) {
  // convert base64/URLEncoded data component to raw binary data held in a string
  var byteString;
  if (dataURI.split(',')[0].indexOf('base64') >= 0)
    byteString = atob(dataURI.split(',')[1]);
  else
    byteString = unescape(dataURI.split(',')[1]);

  // separate out the mime component
  var mimeString = dataURI.split(',')[0].split(':')[1].split(';')[0];

  // write the bytes of the string to a typed array
  var ia = new Uint8Array(byteString.length);
  for (var i = 0; i < byteString.length; i++) {
    ia[i] = byteString.charCodeAt(i);
  }

  return new Blob([ia], {
    type: mimeString
  });
}

// add button event
buttonGo.onclick = function () {
    mobileCanvas.style.display = 'none';

    isPaused = false;
    scanBarcode();
    buttonGo.disabled = true;
};

// scan barcode
function scanBarcode() {
    barcode_result.textContent = "";

      if (ZXing == null) {
          buttonGo.disabled = false;
          alert("Barcode Reader is not ready!");
          return;
      }

  var data = null,
    context = null,
    width = 0,
    height = 0,
    dbrCanvas = null;

    context = mobileCtx;
    width = mobileVideoWidth;
    height = mobileVideoHeight;
    dbrCanvas = mobileCanvas;


    context.drawImage(videoElement, 0, 0, width, height);

    var vid = document.getElementById("video");
    console.log("video width: " + vid.videoWidth + ", height: " + vid.videoHeight);
    var barcodeCanvas = document.createElement("canvas");
    barcodeCanvas.width = vid.videoWidth;
    barcodeCanvas.height = vid.videoHeight;
    var barcodeContext = barcodeCanvas.getContext('2d');
    var imageWidth = vid.videoWidth, imageHeight = vid.videoHeight;
    barcodeContext.drawImage(videoElement, 0, 0, imageWidth, imageHeight);
    // read barcode
    var imageData = barcodeContext.getImageData(0, 0, imageWidth, imageHeight);
    var idd = imageData.data;
    var image = ZXing._resize(imageWidth, imageHeight);
    console.time("decode barcode");
    
    for (var i = 0, j = 0; i < idd.length; i += 4, j++) {
      ZXing.HEAPU8[image + j] = idd[i];
    }

    var err = ZXing._decode_any(decodePtr);
    console.timeEnd('decode barcode');
    console.log("error code", err);
    if (err == -2) {
      setTimeout(scanBarcode, 30);
    }
}
// https://github.com/samdutton/simpl/tree/gh-pages/getusermedia/sources 
var videoSelect = document.querySelector('select#videoSource');

navigator.mediaDevices.enumerateDevices()
  .then(gotDevices).then(getStream).catch(handleError);

videoSelect.onchange = getStream;

function gotDevices(deviceInfos) {
    for (var i = deviceInfos.length - 1; i >= 0; --i) {
      var deviceInfo = deviceInfos[i];
      var option = document.createElement('option');
      option.value = deviceInfo.deviceId;
      if (deviceInfo.kind === 'videoinput') {
        option.text = deviceInfo.label || 'camera ' +
          (videoSelect.length + 1);
        videoSelect.appendChild(option);
      } else {
        console.log('Found one other kind of source/device: ', deviceInfo);
      }
  }
}

function getStream() {
    buttonGo.disabled = false;
    if (window.stream) {
        window.stream.getTracks().forEach(function(track) {
            track.stop();
        });
    }

    var constraints = {
      video: {
        deviceId: {exact: videoSelect.value}
      }
    };

    navigator.mediaDevices.getUserMedia(constraints).
      then(gotStream).catch(handleError);
}

function gotStream(stream) {
    window.stream = stream; 
    videoElement.srcObject = stream;
}

function handleError(error) {
    console.log('Error: ', error);
}
