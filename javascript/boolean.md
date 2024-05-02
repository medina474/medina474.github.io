---
title: Booléen
---

<pre><code>false</pre></code>
<script>if (false) document.write('vrai'); else document.write('faux');</script>

<pre><code>0</pre></code>
<script>if (0) document.write('vrai'); else document.write('faux');</script>

<pre><code>"0"</pre></code>
<script>if ("0") document.write('vrai'); else document.write('faux');</script>

<script>document.write(false == "0.0");</script>

<script>document.write(false == "000");</script>

<script>document.write(false == "0.00");</script>

<script>document.write(false == "");</script>

<script>document.write(false == {});</script>

<script>document.write(false == []);</script>


<script>document.write(false == null);</script>

<script>document.write(false == undefined);</script>


<script>document.write(false == NaN);</script>
coercion
<script>
if ([0]) {
    document.write([0] == true); //false
    document.write(!![0]); //true
}

if ("potato") {
    document.write("potato" == false); //false
    document.write("potato" == true); //false
}
</script>
