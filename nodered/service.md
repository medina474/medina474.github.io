---
title: Service Web avec NodeRed
---

### Insérer plusieurs enregistrements

```javascript
msg.collection = msg.req.params.collection;
msg.operation = "insertMany";
msg.payload = [msg.payload];
return msg;
```

### Trouver tout

```javascript
msg.collection = msg.req.params.collection;
msg.operation = "find";
msg.payload = [];
return msg;
```

### Trouver Un 

```javascript
msg.collection = msg.req.params.collection;
msg.operation = "findOne";
msg.payload = [{ "_id": msg.req.params.id }];

return msg;
```

### Compter

```javascript
msg.collection = msg.req.params.collection;
msg.operation = "count";
msg.payload = [];

return msg;
```

```javascript
msg.operation = "deleteMany";
msg.collection = msg.req.params.collection;
msg.payload = [];
return msg;
```

```javascript
msg.operation = "deleteOne";
msg.collection = msg.req.params.collection;
msg.payload = [{ "_id": msg.req.params.id }];

return msg;
```

```javascript
msg.operation = "updateOne";
msg.collection = msg.req.params.collection;
msg.payload = [{ "_id": msg.req.params.id}, { "$set": msg.payload }];
return msg;
```

```javascript
msg.operation = "updateOne";
msg.collection = msg.req.params.collection;

var values = {};
Object.entries(msg.payload).forEach(entry => {
    const [key, value] = entry;
    values[key] = new Date(value);
});

msg.payload = [{ "_id": msg.req.params.id }, 
{ "$set": values }];
return msg;
```

```javascript
msg.operation = "find";
msg.collection = msg.req.params.collection;

var re = new RegExp(msg.req.params.critere,"i");
//i = case insensitive / non sensible aux majuscules
msg.payload = [{ "prenom": re }];
return msg;
```

```javascript
msg.operation = "find";
msg.collection = msg.req.params.collection;
msg.payload = [{ "naissance": { $gt: new Date(msg.req.params.date) } }];
return msg;
```