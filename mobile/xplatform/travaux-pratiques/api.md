---
title: API
---

Un Future est un objet qui représente une valeur ou une erreur qui sera disponible à un moment donné dans le **futur**. Les Futures sont utilisés pour les opérations asynchrones, comme la récupération de données d'une API, la lecture de fichiers, ou toute autre tâche qui peut prendre un certain temps à s'exécuter.

```dart
Future<List<String>> fetchActeurs() async {
  return ["Acteur A", "Acteur B", "Acteur C"];
}
```

```dart
FutureBuilder<List<String>>(
  future: fetchActeurs(),
  builder: (context, snapshot) { }
```

```dart
Future<List<Acteur>> fetchActeurs() async {
    final response = await http.get(
        Uri.parse(
            "https://morseweiswlpykaugwtd.supabase.co/rest/v1/acteurs?select=*"),
        headers: {
          "Content-type": "application/json",
          "apikey":
              "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6Im1vcnNld2Vpc3dscHlrYXVnd3RkIiwicm9sZSI6ImFub24iLCJpYXQiOjE3MDY5NTcxMjgsImV4cCI6MjAyMjUzMzEyOH0.UV5XCINWe-Jaw6_-787Veh-LxjzUVudArvrgH6Ycf30"
        });

    if (response.statusCode == 200) {
      List<dynamic> data = json.decode(response.body);
      return data.map((elt) => date["nom"].toString()).toList();
    } else {
      throw Exception("Erreur du web service");
    }
  }
```


```dart
if (snapshot.connectionState == ConnectionState.waiting) {
  return const Center(child: CircularProgressIndicator());
}
```

```dart
else if (snapshot.hasError) {
  return Center(child: Text('Erreur : ${snapshot.error}'));
} 
``` 

```dart
else {
  return ListView.builder(
    itemCount: snapshot.data!.length,
    itemBuilder: (context, index) {
      return ListTile(title: Text(acteurs[index]));
    });
}
```

### JSON to Class


