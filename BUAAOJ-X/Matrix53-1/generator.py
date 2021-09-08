from cyaron import *

max_node = 1000000

for i in range(5):
    io = IO(str(i + 1) + '.in', str(i + 1) + '.out')
    tree = Graph.tree(max_node)
    leaf = []
    for i in tree.edges:
        if len(i) == 1:
            leaf.append(randint(0, 10000))
    io.input_writeln(max_node)
    io.input_writeln(tree.to_str(output=Edge.unweighted_edge))
    io.input_write(leaf)
    io.output_gen('D:\\Workspace\\algo\\BUAAOJ-X\\Matrix53-1\\standard.exe')
