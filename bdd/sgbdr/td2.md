---
title: Travaux dirigés
---

### 1. Nombre de clients

```sql
select count(*) from customers;
```

### 2. Nombre d'albums

```sql
select count(*) from albums;
```
### 3. Nombre d'artistes

```sql
select count(*) from artists;
```

### 4. Liste des pays

```sql
select distinct country from customers;
```

Utilisation de `distinct` pour supprimer les doublons.

### 5. Nombre de clients par pays

```sql
select country, count(*) from customers group by Country order by count(*) desc;
```

### 6. Nombre de pistes par genre

```sql
select g.Name, count(*) as nb from tracks t 
inner join genres g on g.GenreId = t.GenreId 
group by g.GenreId order by nb desc;
```

### 7. Nombre d'albums par artiste

```sql
select a.Name, count(*) as nb from artists a 
inner join albums b on b.ArtistId = a.ArtistId 
group by a.Name order by nb desc;
```

### 8. Nombre de piste par artiste

```sql
select a.Name, count(*) as nb from artists a 
inner join albums b on a2.ArtistId = a.ArtistId 
inner join tracks t on t.AlbumId = b.AlbumId 
group by a.Name 
order by nb desc;
```

### 9. Nombre de minute de musique par album

```sql
select a.Title , sum(t.Milliseconds/60000) as duree 
from tracks t 
inner join albums a on a.AlbumId = t.AlbumId 
group by a.Title 
order by duree desc;
```

### 10. Recette par piste

```sql
select t.Name, sum(ii.UnitPrice*ii.Quantity) as recette 
from tracks t 
inner join invoice_items ii on ii.TrackId = t.TrackId
group by t.Name order by recette desc;
```

### 9. Recette par album

```sql
select a.Title, sum(ii.UnitPrice*ii.Quantity) as recette
from tracks t 
inner join invoice_items ii on (ii.TrackId = t.TrackId)
inner join albums a on a.AlbumId = t.AlbumId 
group by a.Title 
order by recette desc;
```

### 10. Les 3 meilleurs clients

```sql
select c.FirstName, c.LastName, sum(i.Total) as total
from customers c
inner join invoices i on i.CustomerId = c.CustomerId 
GROUP by c.CustomerId 
order by total DESC 
limit 3;
```

### 11. Les genres écoutés par Isabelle Mercier

```sql
select distinct g.Name from genres g 
inner join tracks t  on t.GenreId  = g.GenreId 
inner join invoice_items ii on ii.TrackId = t.TrackId 
inner join invoices i on ii.InvoiceId = i.InvoiceId 
inner join customers c  on c.CustomerId = i.CustomerId 
where c.FirstName = 'Isabelle' and c.LastName ='Mercier';
```
Attention l'égalité est stricte sur FirstName et LastName (respect des majuscules / minuscules)

## Utilisation des dates

### 12. Recette après le 01/05/2013

```sql
select sum(i.Total) from invoices i where i.InvoiceDate > DATETIME('2013-05-01');
```

### 13. Recette entre le 15/04/2012 et le 20/06/2012

```sql
select sum(i.Total) 
from invoices i 
where i.InvoiceDate between DATETIME('2012-04-15') and DATETIME('2012-06-20');
```

### 14. Recette du mois de février 2012

```sql
select sum(i.Total) 
from invoices i 
where STRFTIME('%m/%Y', i.InvoiceDate) = '02/2012'
```

STRFTIME (string from datetime) permet de formater au format de texte un date. Le format est complètement libre et personnalisable. 

### 15. Recettes par mois

```sql
select STRFTIME('%Y-%m', i.InvoiceDate) as mois,
  sum(i.Total)
from invoices i 
group by mois
order by mois
```

### 16. Recette de l'année 2013

```sql
select sum(i.Total) 
from invoices i 
where STRFTIME('%Y', i.InvoiceDate) = '2013'
```
## Recherche sur le texte

### 17. Liste des pistes qui contiennent le mot Love

```sql
select t.Name from tracks t 
where t.NAME LIKE '%love%';
```
L'opérateur LIKE ne tient pas compte de la différence minuscule/majuscule

### 18. Liste des pistes qui contiennent les lettres Sun

```sql
select t.Name from tracks t 
where t.NAME LIKE '%SUN%';
```

### 19. Liste des pistes qui contiennent le mot Sun

```sql
select t.Name from tracks t 
where t.NAME LIKE 'SUN %' OR 
      t.NAME LIKE '% SUN' OR 
      t.NAME LIKE '% SUN %';
```

## Cohérence

### 20. Le total de chaque facture est il juste ?

```sql
select i.Total, sum(ii.UnitPrice*ii.Quantity) as somme,
printf('%.20f', i.Total - sum(ii.UnitPrice*ii.Quantity))
from invoices i
inner join invoice_items ii on ii.InvoiceId = i.InvoiceId 
group by i.InvoiceId 
HAVING Abs(i.Total - somme) >= 0.01
```

ou en utilisant ROUND : HAVING i.Total <> Round(somme,2)

### 21. Existe t il des pistes dont le prix unitaire a évolué ?

```sql
select t.Name from tracks t
left join invoice_items ii on ii.TrackId = t.TrackId 
where t.UnitPrice <> ii.UnitPrice 
```
