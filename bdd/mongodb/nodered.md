---
title: NodeRed avec MongoDB
---

Utiliser MongoDB avec NodeRed

[Éditer](/linux/nano) le fichier `~\.node-red\settings.js` et ajouter dans dans la fonction `functionGlobalContext`

```json
functionGlobalContext: {
  ObjectId : require('mongodb').ObjectID,
},
```

Puis dans la function

```javascript
var ObjectId = global.get('ObjectId');

msg.payload=[{
  "_id": ObjectId("5c9156c7f8c3ec3259454571")
}];

return msg;
```
