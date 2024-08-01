Associated with CSE310 at Arizona State University.

This project is the essential part of a navigation system. It reads in either a directed graph or an undirected graph G with n vertices and m edges from a file specified by the command-line (with proper arguments). It then takes corresponding actions for given instructions from stdin. Besides the Stop instruction, valid instructions include:

(i) graph printing instruction (PrintADJ)

(ii) path computation instructions (SinglePair and SingleSource)

(iii) length/path printing instructions (PrintLength and PrintPath)

Both SinglePair and SingleSource path computations have worst-case time complexity O(m log n). Path printing has worst-case time complexity O(n). Length printing has worst-case time complexity O(1). Memory is allocated when needed, and released when it is no longer needed.
