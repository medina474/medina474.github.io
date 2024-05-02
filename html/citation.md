---

title: Citation
---

## Citation longue

<pre><code class="html">&lt;blockquote cite="http://www.b..."&gt;C’était un calmar ... chevelure des furies.&lt;/blockquote&gt;</code></pre>

<blockquote cite="https://fr.wikisource.org/wiki/Vingt_mille_lieues_sous_les_mers/Partie_2/Chapitre_18">
C’était un calmar de dimensions colossales, ayant huit mètres de longueur. Il marchait à reculons avec une extrême vélocité dans la direction du Nautilus. Il regardait de ses énormes yeux fixes à teintes glauques. Ses huit bras, ou plutôt ses huit pieds, implantés sur sa tête, qui ont valu à ces animaux le nom de céphalopodes, avaient un développement double de son corps et se tordaient comme la chevelure des furies.
</blockquote>

L'attribut <code>cite</code> permet de spécifier une URL indiquant la source de la citation.

## Citation courte

Suite aux changements climatiques, les ouragans sont de plus en plus violents, et malheureusement <q>On peut braver les lois humaines, mais non résister aux lois naturelles.</q>

<pre><code class="html">&lt;p&gt; ... et malheureusement &lt;q&gt;On peut braver ... lois naturelles.&lt;/q&gt;</code> ...&lt;/p&gt;</pre>

<p> L'élément permet d'inclure dans un texte une citation courte.</p>


## Bibliographie

<p>Cet extrait provient de <cite>Vingt mille lieues sous les mers</cite> de Jules Verne.</p>

<pre><code class="html">Cet extrait provient de  &lt;cite&gt;Vingt mille lieues sous les mers&lt;/cite&gt;</code></pre>

<p>L'élément <code>cite</code> définit le titre d'un livre, d'une chanson, d'un film, ....</p>

<pre><code class="html">&lt;figure&gt;
    &lt;blockquote&gt;
 "That monster custom, who all sense doth eat
 Of habit's devil," &lt;abbr title="et cetera"&gt;&c.&lt;/abbr&gt; not in Folio
 
 "What a falling off was there !
 From me, whose love was of that dignity
 That it went hand in hand even with the vow
 I made to her in marriage, and to decline
 Upon a wretch."
    &lt;/blockquote&gt;
    &lt;footer&gt;
        — &lt;cite class="title"&gt;Shakespeare manual&lt;/cite&gt; by &lt;cite class="author"&gt;Frederick Gard Fleay&lt;/cite&gt;, p19 (in Google Books)
    &lt;/footer&gt;
</figure>
</code></pre>

<figure>
    <blockquote>
 "That monster custom, who all sense doth eat
 Of habit's devil," <abbr title="et cetera">&c.</abbr> not in Folio
 
 "What a falling off was there !
 From me, whose love was of that dignity
 That it went hand in hand even with the vow
 I made to her in marriage, and to decline
 Upon a wretch."
    </blockquote>
    <footer>
        — <cite class="title">Shakespeare manual</cite> by <cite class="author">Frederick Gard Fleay</cite>, p19 (in Google Books)
    </footer>
</figure>

</body>
</html>
