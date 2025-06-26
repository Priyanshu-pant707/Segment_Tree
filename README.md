# Segment_Tree
All about the segment tree



Its is an efficient data structure that allows
 -> Efficient Querying of intervals/range.
 -> Efficient updating of intervals/range

----------------------------------------*-----------------------------------

# Range queries to find :
 1-> sum
 2-> minimum
 3->maximum etc.....

 segment tree will come to roll up.

-----------------------------------------*----------------------------------


# HOW TO BUILD SEGMENT TREE??...

certain points to know about the segment tree:
-->IT WILL BE A BINARY TREE. EXCLUDING LEAFNODE
--> let array be  {3,1,2,7,1}
-->each node will cover a certain range eg.(a,b).
-->mid=l+r/2;
-->left range will be (l,m) and the right range will be (m+1,r).
-->find mid till you get (m,m) => l==r.
-->root will represent the entire array and the leaf node will represent the single elements.
-->no leaf will represent the segment and interval.
-->height of tree-> logn;
-->height diff between left subtree and right subtree will not be more than one.

--> number of node required to build segment tree => n+n/2+n/4+....+1. ~ 2N-1.


# WHY NOT USING PREFIX SUM ARRAY??..(RANGE SUM)





# CODE :

BuildTree()
![alt text](<Screenshot 2025-06-26 194829.png>)


