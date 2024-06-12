---
title: API
---

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
      return data.map((elt) => Acteur.fromJson(elt)).toList();
    } else {
      throw Exception("Erreur du web service");
    }
    //return ["Acteur A", "Acteur B", "Acteur C"];
  }
```

```dart
FutureBuilder<List<Acteur>>(
  future: fetchActeurs(),
  builder: (context, snapshot) { }
```

```dart
if (snapshot.connectionState == ConnectionState.waiting) {
  return const Center(child: CircularProgressIndicator());
} else if (snapshot.hasError) {
  return Center(child: Text('Erreur : ${snapshot.error}'));
} else {
``` 

```dart
return ListView.builder(
  itemCount: snapshot.data!.length,
```
