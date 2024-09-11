Le nombre de produit par catégories

```sql
SELECT c.CategoryName, COUNT(p.ProductID) AS ProductCount
FROM categories c
JOIN products p ON c.category_id = p.category_id
GROUP BY c.CategoryName;
```

Les produits jamais commandés

```sql
select * from products p 
left join order_details od on od.ProductID = p.ProductID 
where od.OrderDetailID is null;
```

Les ventes mois par mois de Dodsworth

```sql
select year(OrderDate), month(OrderDate), d.unit_price * d.quantity 
from order_details d
join orders o on o.OrderID = d.OrderID 
join employees y on y.employee_id = o.employee_id 
where LastName = 'Dodsworth'
group by year(OrderDate), month(OrderDate)
```

```sql
CREATE TABLE IF NOT EXISTS calendrier (
  DateValue DATE PRIMARY KEY,
  YearValue INT,
  MonthValue INT,
  DayValue INT,
  WeekDayName VARCHAR(10),
  WeekDayNumber INT,
  WeekNumber INT,
  QuarterValue INT
);
```

```sql
SET SESSION max_recursive_iterations = 100000;

INSERT INTO calendrier 
WITH RECURSIVE CalendarCTE AS (
    SELECT 
        '2020-01-01' AS DateValue,
        YEAR('2020-01-01') AS YearValue,
        MONTH('2020-01-01') AS MonthValue,
        DAY('2020-01-01') AS DayValue,
        DAYNAME('2020-01-01') AS WeekDayName,
        WEEKDAY('2020-01-01') + 1 AS WeekDayNumber, -- WEEKDAY retourne de 0 à 6, on ajuste pour avoir 1 à 7
        WEEK('2020-01-01', 3) AS WeekNumber, -- Mode 3 : semaines commencent le lundi
        QUARTER('2020-01-01') AS QuarterValue
    UNION ALL
    SELECT
        DATE_ADD(DateValue, INTERVAL 1 DAY),
        YEAR(DATE_ADD(DateValue, INTERVAL 1 DAY)),
        MONTH(DATE_ADD(DateValue, INTERVAL 1 DAY)),
        DAY(DATE_ADD(DateValue, INTERVAL 1 DAY)),
        DAYNAME(DATE_ADD(DateValue, INTERVAL 1 DAY)),
        WEEKDAY(DATE_ADD(DateValue, INTERVAL 1 DAY)) + 1,
        WEEK(DATE_ADD(DateValue, INTERVAL 1 DAY), 3),
        QUARTER(DATE_ADD(DateValue, INTERVAL 1 DAY))
    FROM CalendarCTE
    WHERE DATE_ADD(DateValue, INTERVAL 1 DAY) <= '2030-12-31'
)
SELECT * FROM CalendarCTE;
```

```sql
select c.YearValue , c.MonthValue, sum(montant)
from calendrier c 
left join 
(select 
o.OrderDate, d.unit_price * d.quantity as montant
from order_details d
left join orders o on o.OrderID = d.OrderID 
left join employees y on y.employee_id = o.employee_id
where LastName = 'Dodsworth') k on k.OrderDate = c.DateValue 
group by c.YearValue , c.MonthValue 
```
