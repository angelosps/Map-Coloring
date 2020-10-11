# Map-Coloring
:world_map: Project 4 for the course "Introduction to Programming" in Semester 1.  
A CSP (Constraint Satisfaction Problem) about coloring maps without two adjacent countries having the same color.   
It has been proved that, every map can be colored with no more than 4 colors, using the above restriction.   
Reference for the "Four color theorem": https://en.wikipedia.org/wiki/Four_color_theorem.  
The simplest version of the project is to read an uncolored map and color it using at most 4 colors. 
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

Here is an example of representing validly a uncolored map.

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
