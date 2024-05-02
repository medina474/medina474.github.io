<!doctype html>
<html>
<head>
    <meta charset='utf-8'>
	<title>Javascript</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
	<link rel="stylesheet" href="/assets/lib/highlight.js/default.css">
	<script src="/assets/lib/highlight.js/highlight.pack.js"></script>
    <script>hljs.initHighlightingOnLoad();</script>
	<script>
        String.prototype.lpad = function(padString, length) {
            var str = this;
            while (str.length < length)
                str = padString + str;
            return str;
        }
        
        b=''
		if (typeof b != 'undefined' && b)
            console.log('true');
        else
            console.log('false');
	</script>
</head>
<body>

<h3>Opérateurs</h3>


<h4>précédence 20</h4>
Groupe ()
<pre><code class="javascript">5 * (4 + 2) = 5 * 6 = <script>document.write(5 * (4 + 2));</script></pre></code>

<h4>précédence 19</h4>

<h4>précédence 18</h4>
Appel de fonction

new

<h4>précédence 17</h4>
Post Incrémentation
<pre><code class="javascript">5 + 3++ = 5 * 6 = <script>document.write(5 + 3++);</script></pre></code>

Post Décrémentation
<pre><code class="javascript">5 + 3-- = 5 * 6 = <script>document.write(5 + 3--);</script></pre></code>

<h4>précédence 16</h4>

<h4>précédence 15</h4>

Exponentiation, associativité à droite 	
<pre><code class="javascript">5 ** 3 ** 2 = 5 ** 9 = <script>document.write(5 ** 3 ** 2);</script></pre></code>

<h4>précédence 14</h4>

Multiplication, associativité à gauche
<pre><code class="javascript">5 * 3 * 2 = 15 * 2 = <script>document.write(5 * 3 * 2);</script></pre></code>

Division, associativité à gauche 	
<pre><code class="javascript">5 / 3 = <script>document.write(5 / 3);</script></pre></code>

Reste, associativité à gauche 	
<pre><code class="javascript">5 % 3 = <script>document.write(5 % 3);</script></pre></code>

<h4>précédence 13</h4>

Addition, associativité à gauche 	
<pre><code class="javascript">5 + 3 = <script>document.write(5 + 3);</script></pre></code>

Soustraction, associativité à gauche
<pre><code class="javascript">5 - 3 = <script>document.write(5 - 3);</script></pre></code>

<h4>précédence 12</h4>

Décalage binaire à gauche, associativité à gauche
<pre><code class="javascript">0b0000001001010001 << 1 = 
0b<script>document.write((0b0000001001010001 << 1).toString(2).lpad("0", 16));</script></pre></code>

Décalage binaire à droite, associativité à gauche
<pre><code class="javascript">0b10000000000000001000001001010001 >> 1  = 
0b<script>document.write((0b10000000000000001000001001010001 >> 1).toString(2).lpad("0", 16));</script></pre></code>

Décalage binaire à droite non-signé, associativité à gauche
<pre><code class="javascript">0b10000000000000001000001001010001 >>> 1  = 
0b<script>document.write((0b10000000000000001000001001010001 >>> 1).toString(2).lpad("0", 32));</script></pre></code>

<h4>précédence 11</h4>

<h4>précédence 10</h4>

<h4>précédence 9</h4>

<h4>précédence 8</h4>

<h4>précédence 7</h4>

<h4>précédence 6</h4>
ET logique, associativité à gauche 	
<pre><code class="javascript">true && false = <script>document.write(true && false);</script></pre></code>

<h4>précédence 5</h4>
OU logique, associativité à gauche 	
<pre><code class="javascript">true || false = <script>document.write(true || false);</script></pre></code>

<h4>précédence 4/h4>

<h4>précédence 3</h4>

</body>
</html>
