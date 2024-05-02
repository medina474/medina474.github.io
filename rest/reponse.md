
```javascript
module.exports = (db) => {

    const router = require('express').Router();
  
    router.get('/', async (req, res) => {
      const data = await db.any("SELECT * from personne");
      res.status(200).json(data);
    });

    router.get('/:id', async (req, res) => {
      const data = await db.any("SELECT * from personne where id = $1");
      res.status(200).json(data);
    });

    router.post('/', async (req, res) => {
      try {
        const data = await db.one("insert into personne (nom, prenom, nationalites) VALUES ($1, $2, $3) RETURNING id",
          [req.body.nom, req.body.prenom, req.body.nationalites])
        res.status(201).json(data);
      }
      catch(reason) {
        res.status(500).json(reason);
      }
    });

    router.put('/:id', async (req, res) => {
      try {
        const data = await db.one("update personne set nom = $2, prenom = $3, nationalites = $4 where id = $1 RETURNING id",
          [req.params.id, req.body.nom, req.body.prenom, req.body.nationalites])
        res.status(201).json(data);
      }
      catch(reason) {
        res.status(500).json(reason);
      }
    });

    router.delete('/:id', async (req, res) => {
      try {
        data = await db.one("delete from personne where id = $1 RETURNING id", req.params.id)
        res.status(200).json(data);
      }
      catch(reason) {
          res.status(500).json(reason);
      }
    });

    return router;
}
```