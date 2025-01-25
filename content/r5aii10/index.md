---
title: Informatique spécialisée
---

[SQLite dans un programme C](sqlite)

[Télémétrie](telemetry)
- [Journaux](log) 

- [Installation de Grafana](grafana) 
- [Installation de Loki](log/loki)
- [Installation de Prometheus](prometheus)
- Implémenter [libprom](libprom)
- [Communication réseau](net)

```mermaid
graph LR;
  A(Grafana) --> B(Loki)
```


<script type="module">
  import mermaid from 'https://cdn.jsdelivr.net/npm/mermaid@11/dist/mermaid.esm.min.mjs';
  mermaid.initialize({ startOnLoad: true });
  await mermaid.run({
  querySelector: '.language-mermaid',
});
</script>
