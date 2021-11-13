from cyaron import *

code_path = 'D:/Workspace/algo/E5-B/'

# big data
io = IO('1.in', '1.out')
io.input_writeln(500, 1000, 250000)
graph = Graph.graph(500, 1000, directed=True, weight_limit=(0, 10000000))
io.input_writeln(graph.to_str(shuffle=True))
for u in range(1, 501):
    for v in range(1, 501):
        io.input_writeln(u, v)
io.output_gen(code_path + 'standard.exe')
io.close()

# big data
io = IO('2.in', '2.out')
io.input_writeln(500, 250000, 250000)
graph = Graph.graph(500, 250000, directed=True, weight_limit=(0, 10000000))
io.input_writeln(graph.to_str(shuffle=True))
for u in range(1, 501):
    for v in range(1, 501):
        io.input_writeln(u, v)
io.output_gen(code_path + 'standard.exe')
io.close()
