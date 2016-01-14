Coding Standards
================

* Only use spaces for indentation. Tabs are not allowed.
* Spaces at the end of lines not allowed, all files must end with a newline.
* Try to limit line length to 100 characters
* Coding style is BSD

```C++
void f(int arg)
{
  if(cond)
  {
    while(0)
    {
      something;
    }
  }
}
```

Special indenting may be used when splitting a function, meta-function or macro call over several lines:

```C++
f( a
 , g(b, c)
 , h( d
    , e
    )
 , x
 );

typename f< a
          , typename g<b, c>::type
          , typename h< d
                      , e
                      >::type
          , x
          >::type;
```

Putting the comma on the left is useful for easily adding/removing lines.

* Some files may exceptionally use different coding style, but it must be self-contained. When editing such files, respect the coding style that the file has.

Includes and Dependencies
=========================

All files must explicitly include and/or depend on the components that they use, regardless of whether they may already depend on it implicitly in certain situations.

In particular, any file using a type, function, macro or meta-function must include the file that it is defined in, and must not include any other file that the ones that are strictly necessary.

Git usage
=========

A reasonable attempt to make the master repository always in a stable state should be made; to achieve this commits should be atomic and do all the required changes affected by the other changes made everywhere.

Commits must be self-contained but also minimal, use separate commits to modify separate things.

When doing a pull request, use a topical branch containing exclusively a particular improvement you'd like to see reviewed and merged.
