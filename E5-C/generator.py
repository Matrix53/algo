from cyaron import *

code_path = 'D:/Workspace/algo/E5-C/'

# big data
io = IO('1.in', '1.out')
io.input_writeln(100000, 200000)
graph = Graph.DAG(100000, 200000, loop=False)
io.input_writeln(graph.to_str(shuffle=True, output=Edge.unweighted_edge))
io.output_gen(code_path + 'standard.exe')
io.close()

# big data
io = IO('2.in', '2.out')
io.input_writeln(100000, 100000)
graph = Graph.DAG(100000, 100000, loop=False)
io.input_writeln(graph.to_str(shuffle=True, output=Edge.unweighted_edge))
io.output_gen(code_path + 'standard.exe')
io.close()
