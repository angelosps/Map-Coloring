# Map-Coloring
:world_map: Project 4 for the course "Introduction to Programming" in Semester 1.  
A CSP (Constraint Satisfaction Problem) about coloring maps without two adjacent countries having the same color.   
It has been proved that, every map can be colored with no more than 4 colors, using the above restriction.   
Reference for the "Four color theorem": https://en.wikipedia.org/wiki/Four_color_theorem.  

The simplest version of the project is to read an uncolored map and color it using at most 4 colors or returns an error message if the map can't be colored.  
A map is described by a text, where each line represents a country. The first word represents the color of the country 
("nocolor" for uncolored country), the second word is the name of the country, and the remaining words are the name of its neighbours.

An example of this line is:  

``` bash
<color> <country> <neighbour1> <neighbour2> <neighbour3> ...
```
To be valid, the description of a map, must follow the rule: if a country **A** is adjacent to country **B**, 
then the country **A** must contain the country **B** in its neighbours and the country **B** must contain the country **A** in its neighbours.  
For example:

``` bash
<color> <A> <B> <neighbour2> <neighbour3> ...
<color> <B> <A> <neighbour2> <neighbour3> ...

```

Here is an example of a valid representation of an uncolored map.

``` bash

$ cat Balkans.txt
nocolor Albania Greece Montenegro North_Macedonia Serbia
nocolor Bosnia_and_Herzegovina Croatia Montenegro Serbia
nocolor Bulgaria Greece North_Macedonia Romania Serbia Turkey
nocolor Croatia Bosnia_and_Herzegovina Montenegro Serbia Slovenia
nocolor Greece Albania Bulgaria North_Macedonia Turkey
nocolor Montenegro Albania Bosnia_and_Herzegovina Croatia Serbia
nocolor North_Macedonia Albania Bulgaria Greece Serbia
nocolor Romania Bulgaria Serbia
nocolor Serbia Albania Bosnia_and_Herzegovina Bulgaria Croatia Montenegro North_Macedonia Romania nocolor Slovenia Croatia
nocolor Turkey Bulgaria Greece
$

```

An output example for the above uncolored map is the following colored map:

``` bash

$ ./mapcol < Balkans.txt
yellow Albania Greece Montenegro North_Macedonia Serbia
yellow Bosnia_and_Herzegovina Croatia Montenegro Serbia
green Bulgaria Greece North_Macedonia Romania Serbia Turkey
blue Croatia Bosnia_and_Herzegovina Montenegro Serbia Slovenia
red Greece Albania Bulgaria North_Macedonia Turkey
green Montenegro Albania Bosnia_and_Herzegovina Croatia Serbia
blue North_Macedonia Albania Bulgaria Greece Serbia
blue Romania Bulgaria Serbia
red Serbia Albania Bosnia_and_Herzegovina Bulgaria Croatia Montenegro North_Macedonia Romania yellow Slovenia Croatia
blue Turkey Bulgaria Greece
$

```
  

### Input the map from a file (option -i) ###

This feature (-i) allows you to read the map directly from a text file instead of the standard input.
In the example below, the given map (from the file using the -i command) cannot be colored using 4 colors and so the appropriate message is returned.

``` bash

$ cat No4colors.txt nocolor c1 c2 c3 c4 c5
nocolor c2 c1 c3 c4 c5
nocolor c3 c1 c2 c4 c5
nocolor c4 c1 c2 c3 c5
nocolor c5 c1 c2 c3 c4
$
$ ./mapcol -i No4colors.txt 
Sorry, cannot color the given map 
$

```


### Check coloring validity of the map (option -c) ###

This option allows you to check a given, colored map if it is validly colored. If the map is not validly colored, the program finds and prints the coloring problems have been found (i.e.: more colors used, etc).

Here is an example of using the -c option:

``` bash

$ ./mapcol -i WesternEurope.txt -c
Please, color the map first
$
$ ./mapcol -c
red c1 c2 c3 c4 c5
green c2 c1 c3 c4 c5
blue c3 c1 c2 c4 c5
yellow c4 c1 c2 c3 c5
orange c5 c1 c2 c3 c4
^D
More than 4 colors used
$
$ ./mapcol -c
yellow Albania Greece Montenegro North_Macedonia Serbia yellow Bosnia_and_Herzegovina Croatia Montenegro Serbia
green Bulgaria Greece North_Macedonia Romania Serbia Turkey
yellow Croatia Bosnia_and_Herzegovina Montenegro Serbia Slovenia
red Greece Albania Bulgaria North_Macedonia Turkey
green Montenegro Albania Bosnia_and_Herzegovina Croatia Serbia
blue North_Macedonia Albania Bulgaria Greece Serbia
blue Romania Bulgaria Serbia
red Serbia Albania Bosnia_and_Herzegovina Bulgaria Croatia Montenegro North_Macedonia Romania yellow Slovenia Croatia
blue Turkey Bulgaria Greece
^D
Bosnia_and_Herzegovina - Croatia: Should have different color
Croatia - Bosnia_and_Herzegovina: Should have different color
Croatia - Slovenia: Should have different color
Slovenia - Croatia: Should have different color
$

```


### Coloring partly colored maps ###

The program, also provides the feature of coloring partly colored maps.
In example:

``` bash

$ cat BalkansPartlyColored.txt
yellow Albania Greece Montenegro North_Macedonia Serbia
nocolor Bosnia_and_Herzegovina Croatia Montenegro Serbia
green Bulgaria Greece North_Macedonia Romania Serbia Turkey
nocolor Croatia Bosnia_and_Herzegovina Montenegro Serbia Slovenia
nocolor Greece Albania Bulgaria North_Macedonia Turkey
green Montenegro Albania Bosnia_and_Herzegovina Croatia Serbia
blue North_Macedonia Albania Bulgaria Greece Serbia
nocolor Romania Bulgaria Serbia
red Serbia Albania Bosnia_and_Herzegovina Bulgaria Croatia Montenegro North_Macedonia Romania nocolor Slovenia Croatia
blue Turkey Bulgaria Greece
$
$ ./mapcol -i BalkansPartlyColored.txt
yellow Albania Greece Montenegro North_Macedonia Serbia
yellow Bosnia_and_Herzegovina Croatia Montenegro Serbia
green Bulgaria Greece North_Macedonia Romania Serbia Turkey
blue Croatia Bosnia_and_Herzegovina Montenegro Serbia Slovenia
red Greece Albania Bulgaria North_Macedonia Turkey
green Montenegro Albania Bosnia_and_Herzegovina Croatia Serbia
blue North_Macedonia Albania Bulgaria Greece Serbia
yellow Romania Bulgaria Serbia
red Serbia Albania Bosnia_and_Herzegovina Bulgaria Croatia Montenegro North_Macedonia Romania red Slovenia Croatia
blue Turkey Bulgaria Greece
$

```

### Determining the number of colors (option -n) ###

This option allows you to define the number of colors you want to use for coloring a map using the command "-n <colornum>"

In example:

``` bash

$ ./mapcol -n 5 < No4colors.txt
red c1 c2 c3 c4 c5
green c2 c1 c3 c4 c5
blue c3 c1 c2 c4 c5
yellow c4 c1 c2 c3 c5
orange c5 c1 c2 c3 c4

```

***Note: All options described (-i, -c, -n), can be used together***

### Generating random inputs ###

A random map generator it is provided, so you can check the project. The program "genmap.c" works as follows:

genmap &btncountries> \[ &ltuncolperc> \[ &ltdensity> \[ &ltseed> \[ &ltcolornum> ] ] ] ]
