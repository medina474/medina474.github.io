
<p>This is a paragraph before an <strong>unnumbered</strong> list (<code>ul</code>). Note that the spacing between a paragraph and a list before or after that is hard to tune in a user style sheet. You can't guess which paragraphs are logically related to a list, e.g. as a "list header".</p>
<ul>
<li>One.</li>
<li>Two.</li>
<li>Three. Well, probably this list item should be longer. Note that for short items lists look better if they are compactly presented, whereas for long items, it would be better to have more vertical spacing between items.</li>
<li>Four. This is the last item in this list. Let us terminate the list now without making any more fuss about it.</li>
</ul>

<p>The following is a <code>menu</code> list:</p>

<menu>
<li>One.</li>
<li>Two.</li>
<li>Three. Well, probably this list item should be longer so that it will probably wrap to the next line in rendering.</li>
</menu>

<p>The following is a <code>dir</code> list:</p>
<dir>
<li>One.</li>
<li>Two.</li>
<li>Three. Well, probably this list item should be longer so that it will probably wrap to the next line in rendering.</li>
</dir>

<p>This is a paragraph before a <strong>numbered</strong> list (<code>ol</code>). Note that the spacing between a paragraph and a list before or after that is hard to tune in a user style sheet. You can't guess which paragraphs are logically related to a list, e.g. as a "list header".</p>
<ol>
<li>One.</li>
<li>Two.</li>
<li>Three. Well, probably this list item should be longer. Note that if items are short, lists look better if they are compactly presented, whereas for long items, it would be better to have more vertical spacing between items.</li>
<li>Four. This is the last item in this list. Let us terminate the list now without making any more fuss about it.</li>
</ol>

<p>This is a paragraph before a <strong>definition</strong> list (<code>dl</code>). In principle, such a list should consist of <em>terms</em> and associated definitions. But many authors use <code>dl</code> elements for fancy "layout" things. Usually the effect is not <em>too</em> bad, if you design user style sheet rules for <code>dl</code>which are suitable for real definition lists.</p>
<dl><dt>recursion</dt><dd>see recursion</dd><dt>recursion, indirect</dt><dd>see indirect recursion</dd><dt>indirect recursion</dt><dd>see recursion, indirect</dd><dt>term</dt><dd>a word or other expression taken into specific use in a well-defined meaning, which is often defined rather rigorously, even formally, and may differ quite a lot from an everyday meaning</dd></dl>




<h2>Listes ordonnées</h2>

<p>ol : ordered list</p>

```html
<ol style='list-style-type: decimal'>
```

<ol style="list-style-type: decimal;">
  <li>France</li>
  <li>Mexique</li>
  <li>Allemagne</li>
  <li>Espagne</li>
  <li>U.S.A.</li>
</ol>

```html
<ol style='list-style-type: decimal-leading-zero'>
```

<ol style="list-style-type: decimal-leading-zero;">
  <li>France</li>
  <li>Mexique</li>
  <li>Allemagne</li>
  <li>Espagne</li>
  <li>U.S.A.</li>
</ol>

```html
<ol style='list-style-type: lower-alpha'>
```

<ol style="list-style-type: lower-alpha;">
  <li>France</li>
  <li>Mexique</li>
  <li>Allemagne</li>
  <li>Espagne</li>
  <li>U.S.A.</li>
</ol>

```html
<ol style='list-style-type: lower-latin'>
```

<ol style="list-style-type: lower-latin;">
  <li>France</li>
  <li>Mexique</li>
  <li>Allemagne</li>
  <li>Espagne</li>
  <li>U.S.A.</li>
</ol>

```html
<ol style='list-style-type: upper-alpha'>
```

<ol style="list-style-type: upper-alpha;">
  <li>France</li>
  <li>Mexique</li>
  <li>Allemagne</li>
  <li>Espagne</li>
  <li>U.S.A.</li>
</ol>

```html
<ol style='list-style-type: upper-latin'>
```

<ol style="list-style-type: upper-latin;">
  <li>France</li>
  <li>Mexique</li>
  <li>Allemagne</li>
  <li>Espagne</li>
  <li>U.S.A.</li>
</ol>

<h3>Romain</h3>

```html
<ol style='list-style-type: lower-roman'>
```

<ol style="list-style-type: lower-roman;">
  <li>France</li>
  <li>Mexique</li>
  <li>Allemagne</li>
  <li>Espagne</li>
  <li>U.S.A.</li>
</ol>

```html
<ol style='list-style-type: upper-roman'>
```

<ol style="list-style-type: upper-roman;">
  <li>France</li>
  <li>Mexique</li>
  <li>Allemagne</li>
  <li>Espagne</li>
  <li>U.S.A.</li>
</ol>

```html
<ol style='list-style-type: lower-greek'>
```

<ol style="list-style-type: lower-greek;">
  <li>France</li>
  <li>Mexique</li>
  <li>Allemagne</li>
  <li>Espagne</li>
  <li>U.S.A.</li>
</ol>

```html
<ol style='list-style-type: armenian'>
```

<ol style="list-style-type: armenian;">
  <li>France</li>
  <li>Mexique</li>
  <li>Allemagne</li>
  <li>Espagne</li>
  <li>U.S.A.</li>
</ol>

```html
<ol style='list-style-type: georgian'>
```

<ol style="list-style-type: georgian;">
<li>France</li>
<li>Mexique</li>
<li>Allemagne</li>
<li>Espagne</li>
<li>U.S.A.</li>
</ol>

```html
<ol style='list-style-type: hebrew'>
```

<ol style="list-style-type: hebrew;">
<li>France</li>
<li>Mexique</li>
<li>Allemagne</li>
<li>Espagne</li>
<li>U.S.A.</li>
</ol>

<ol style="list-style-type: cjk-ideographic;">
<li>France</li>
<li>Mexique</li>
<li>Allemagne</li>
<li>Espagne</li>
<li>U.S.A.</li>
</ol>

<h3>Japonais</h3>

```html
<ol style='list-style-type: hiragana'>
```

<ol style="list-style-type: hiragana">
  <li>France</li>
  <li>Mexique</li>
  <li>Allemagne</li>
  <li>Espagne</li>
  <li>U.S.A.</li>
</ol>

```html
<ol style='list-style-type: hiragana-iroha'>
```

<ol style="list-style-type: hiragana-iroha">
  <li>France</li>
  <li>Mexique</li>
  <li>Allemagne</li>
  <li>Espagne</li>
  <li>U.S.A.</li>
</ol>

```html
<ol style='list-style-type: katakana'>
```

<ol style="list-style-type: katakana">
  <li>France</li>
  <li>Mexique</li>
  <li>Allemagne</li>
  <li>Espagne</li>
  <li>U.S.A.</li>
</ol>

```html
<ol style='list-style-type: katakana-iroha'>
```

<ol style="list-style-type: katakana-iroha">
  <li>France</li>
  <li>Mexique</li>
  <li>Allemagne</li>
  <li>Espagne</li>
  <li>U.S.A.</li>
</ol>

```html
<ol start='100'>
```

<ol start='100'>
  <li>France</li>
  <li>Mexique</li>
  <li>Allemagne</li>
  <li>Espagne</li>
  <li>U.S.A.</li>
</ol>

```html
<ol reversed>
```

<ol reversed>
  <li>France</li>
  <li>Mexique</li>
  <li>Allemagne</li>
  <li>Espagne</li>
  <li>U.S.A.</li>
</ol>

```html
<ol>
```

<ol>
  <li value='2'>France</li>
  <li value='6'>Mexique</li>
  <li value='4'>Allemagne</li>
  <li value='7'>Espagne</li>
  <li>U.S.A.</li>
</ol>

<a href="listes/liste-ord-roman">roman</a>


[Listes non ordonnées](liste-non-ordonnée)
[Listes ordonnées](liste-ordonnee.html)
[Listes de définition][definition]
[Position](position)
