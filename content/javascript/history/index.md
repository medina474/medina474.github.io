<script>
window.loadstart = function(event) {
  console.log("window.loadstart");
  console.log(window.history.length);
  console.log("location: " + document.location + ", state: " + JSON.stringify(event.state));
};

window.onload = function(event) {
  console.log("window.onload");
  console.log(window.history.length);
  console.log("location: " + document.location + ", state: " + JSON.stringify(event.state));
};

window.onpopstate = function(event) {
  console.log("window.onpopstate");
  console.log(window.history.length);
  console.log("location: " + document.location + ", state: " + JSON.stringify(event.state));
};

window.onhashchange = function(event) {
  console.log("window.onhashchange");
  console.log(window.history.length);
  console.log("location: " + document.location + ", state: " + JSON.stringify(event.state));
};

window.onbeforeunload = function(event) {
  console.log("window.onbeforeunload");
  console.log(window.history.length);
  console.log("location: " + document.location + ", state: " + JSON.stringify(event.state));
};

window.onunload = function(event) {
  console.log("window.onunload");
  console.log(window.history.length);
  console.log("location: " + document.location + ", state: " + JSON.stringify(event.state));
};

window.onlanguagechange = function(event) {
  console.log("window.onlanguagechange");
  console.log(window.history.length);
  console.log("location: " + document.location + ", state: " + JSON.stringify(event.state));
};

window.onbeforeprint = function(event) {
  console.log("window.onbeforeprint");
  console.log(window.history.length);
  console.log("location: " + document.location + ", state: " + JSON.stringify(event.state));
};

window.onafterprint = function(event) {
  console.log("window.onlanguagechange");
  console.log(window.history.length);
  console.log("location: " + document.location + ", state: " + JSON.stringify(event.state));
};


//window.history.back();
</script>

<script>
//window.history.forward();

stateObj = { title:'test' };
</script>

<button onclick='history.pushState(stateObj, "Titre", "#1");'>push</button>

<button onclick='window.history.go(-1);'>go 1</button>
<button onclick='window.history.go(1);'>go 1</button>



history.pushState(stateObj, "page 2", "bar.html");
history.replaceState(stateObj, "page 2", "bar.html");

var currentState = history.state;
