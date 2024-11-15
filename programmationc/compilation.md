---
title: Compilation
---

Le traitement par le préprocesseur : le fichier source est analysé par le préprocesseur qui effectue des
transformations textuelles dans le fichier source. Substitution de chaine de caractère, des constantes, prise en compte des directives de compilation inclusion des autres fichiers sources...

**La compilation** : C’est la traduction du fichier généré par le préprocesseur en assembleur, c’est-à-dire en une suite d’instruction du microprocesseur. (en mnémonique rendant la lecture possible)

**L’assemblage** : Cette opération transforme le code assembleur en un fichier binaire directement compréhensible par le processeur.(fichiers objets)

**L’édition de liens** : C’est la liaison de tous les fichiers objets utilisés par le programme (source(s), librairies de fonctions standard ou autres...) 

EXECUTABLE

mermaid
Code source -> compilateur -> Assembleur -> Code objet -> Linker -> Fichier exécutable

```mermaid
  graph TD;
      A-->B;
      A-->C;
      B-->D;
      C-->D;
```

<script type="module">
  import mermaid from 'https://cdn.jsdelivr.net/npm/mermaid@11/dist/mermaid.esm.min.mjs';
</script>
<script>
  mermaid.initialize({ startOnLoad: false });
await mermaid.run({
  querySelector: '.language-mermaid',
});
</script>
