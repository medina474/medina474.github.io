---
title: MongoDB
---

Q1 Create a Database and name it as exercises in MongoDB and create a Collection and name it as restaurants.

```javascript
use exerecise db.createCollection("restaurants")
```

Q2 Insert all the data given in the JSON file into this collection.

```javascript
mongoimport --db exerecise --collection restaurants --file /home/achchu/Documents/Uki/project/MongoDBEx/restaurants.json
```
Q1
```javascript
db.restaurants.findOne()
```

Q2 
```javascript
db.restaurants.find()
```

Q3


Q4


Q5


Q6


Q7 


Q8


Q9


Q10


Q9 display the next 5 restaurants after skipping the first 5 in the borough Bronx.



Q12 



Q13 


Q14


Q15 
```javascript
db.restaurants.find({$and:[{cuisine:{$ne:"American"}},{"grades.score":{$gt:70}},{"address.coord.0": { $lt: -65.754168 }}]})
```

Q16
```javascript
db.restaurants.find({cuisine:{$ne:"American"},"grades.score":{$gt:70},"address.coord.0": { $lt: -65.754168 }})
```

Q17 
```javascript
db.restaurants.find({$and:[{cuisine:{$ne:"American"},borough:{$ne:"Brooklyn"},"grades.grade":"A"}]}).sort({cuisine:-1})
```

Q18
```javascript
db.restaurants.find({ name: { $regex: /^Will/ } }, { restaurant_id: 1, name: 1, borough: 1, cuisine: 1, _id: 0 })
```

Q17
```javascript
db.restaurants.find({name:{$regex: /ces$/}}, {"restaurant_id": 1, "name": 1, "borough": 1, "cuisine": 1})
```

Q18 
```javascript
db.restaurants.find({name:{$regex: /Reg/}}, {"restaurant_id": 1, "name": 1, "borough": 1, "cuisine": 1})
```

Q19 
```javascript
db.restaurants.find({$and:[{"borough": "Bronx"}, "cuisine":{ $in: ["American", "Chinese"]}]})
```

Q22

```
db.restaurants.find({"grades.score":{$lte:10}},{restaurant_id:1,name:1,borough:1,cuisine:1})
```

Q23
```
db.restaurants.find({$or:[{$and:[{ cuisine: { $ne: "American"}},{cuisine:{$ne:"chinese"}}]},{name:{$regex:/^will/}}]},{_id:1,name:1,borough:1,cuisine:1})
```

Q24 
```
db.restaurants.find({$and:[{"grades":{$elemMatch:{"grade":"A","score":11,"date":ISODate("2014-08-11T00:00:00Z")}}}]},{_id:1,name:1,grades:1})
```

Q25
```
db.restaurants.find().sort({ name: 1})
```

Q26
```
db.restaurants.find().sort({ name: -1})
```

Q27 
```
db.restaurants.find().sort({cuisine:1,borough:-1})
```

Q28
```
db.restaurants.find({"address.street":{$exists:false}}).count()==0
```

Q29 
```
db.restaurants.find({ "coord": { $type: "double" } })
```

Q30 Write a MongoDB query which will select the restaurant Id, name and grades for those restaurants which return 0 as a remainder after dividing the score by 7.

```
db.restaurants.find({"grades.score":{$mod:[7,0]}},{restaurant_id:1,name:1,grades:1,_id:0})
```
