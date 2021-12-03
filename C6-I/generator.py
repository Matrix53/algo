from cyaron import *

code_path = 'D:/Workspace/algo/C6-I/'

# small data
io = IO('1.in', '1.out')
io.input_writeln(10000)
seq = Sequence(lambda i, f: randint(1, 100000))
io.input_writeln(seq.get(1, 10000))
# Compare.program(code_path + 'standard.exe',
#                 input=io,
#                 std_program=code_path + 'compare.exe')
io.output_gen(code_path + 'standard.exe')
io.close()

# big data
io = IO('2.in', '2.out')
io.input_writeln(100000)
seq = Sequence(lambda i, f: randint(1, 100000))
io.input_writeln(seq.get(1, 100000))
io.output_gen(code_path + 'standard.exe')
io.close()

# hack data
io = IO('3.in', '3.out')
io.input_writeln(99999)
seq = Sequence(lambda i, f: 99999)
io.input_writeln(seq.get(1, 99999))
io.output_gen(code_path + 'standard.exe')
io.close()