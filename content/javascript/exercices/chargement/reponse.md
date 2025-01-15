```javascript
const checkImage = function(path) {
    return new Promise((resolve, reject) => {
        const img = new Image();
        img.onload = () => resolve({path, status: 'ok'});
        img.onerror = () => reject({path, status: 'error'});
        img.src = path;
    });
}
```

