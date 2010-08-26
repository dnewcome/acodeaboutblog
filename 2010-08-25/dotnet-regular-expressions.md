# Exploring matches, groups and captures in .NET regular expressions

I was developing a feature for an application today when I had to implement a quick-and-dirty variable substitution
feature. I decided to use the amazing and simple (and amazingly simple) mustache syntax for my template 
"language". For those of you unfamiliar with mustache, a variable subsitution looks like this:

    {{variable}}

This has the advantage of having a pretty easy pattern to match with regular expressions. In .NET regular expression 
syntax it would look something like this:

    {{.*}}

Those of you that are taking notes will probably recongnize some problems with this expression, even though it
will ostensibly match the form we laid out above.

Before I go any further into this example, I want to introduce a small tool that I wrote a while ago to test out
regular expressions in .NET. It differs slightly from other tools in that it is a very simple and short console tool
but is also interactive. Think of it as a regex repl (read-eval-print loop).

Using the regex repl we can test out our expressions and see how .NET processes the expression. Let's try the above
expression:

<pre>
Enter regex
{{.*?}}
Enter input
this is a {{replace}}ment string
Match: {{replace}}
 Group: {{replace}}
 Capture: {{replace}} Index: 10
</pre>
