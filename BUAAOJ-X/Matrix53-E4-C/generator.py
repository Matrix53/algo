from cyaron import *

code_path = 'D:/Workspace/algo/BUAAOJ-X/Matrix53-E4-C/'

# small data
io = IO('1.in', '1.out')
io.input_writeln(500)
seq = Sequence(lambda i, f: randint(1, 10000))
io.input_writeln(seq.get(1, 500))
io.input_writeln(seq.get(501, 1001))
# Compare.program(code_path + 'standard.exe',
#                 input=io,
#                 std_program=code_path + 'compare.exe')
io.output_gen(code_path + 'standard.exe')
io.close()

# big data
io = IO('2.in', '2.out')
io.input_writeln(1000)
seq = Sequence(lambda i, f: randint(1, 100000000))
io.input_writeln(seq.get(1, 1000))
io.input_writeln(seq.get(1001, 2001))
io.output_gen(code_path + 'standard.exe')
io.close()

# hack data
io = IO('3.in', '3.out')
io.input_writeln(1000)
seq = Sequence(lambda i, f: 100000000)
io.input_writeln(seq.get(1, 1000))
io.input_writeln(seq.get(1001, 2001))
io.output_gen(code_path + 'standard.exe')
io.close()
