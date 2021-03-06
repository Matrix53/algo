from cyaron import *

code_path = 'D:/Workspace/algo/C4-F/'

# small data
io = IO('1.in', '1.out')
io.input_writeln(5)
io.input_writeln(5, 5, 5, 7, 8)
# Compare.program(code_path + 'standard.exe',
#                 input=io,
#                 std_program=code_path + 'compare.exe')
io.output_gen(code_path + 'standard.exe')
io.close()

# big data
io = IO('2.in', '2.out')
io.input_writeln(500)
seq1 = Sequence(lambda i, f: randint(101, 110))
seq2 = Sequence(lambda i, f: 1000)
io.input_writeln(seq1.get(1, 101), seq2.get(1, 399))
io.output_gen(code_path + 'standard.exe')
io.close()

# hack data
io = IO('3.in', '3.out')
io.input_writeln(499)
seq = Sequence(lambda i, f: 1000)
io.input_writeln(seq.get(1, 499))
io.output_gen(code_path + 'standard.exe')
io.close()

# emergency
io = IO('4.in', '4.out')
io.input_writeln(499)
seq1 = Sequence(lambda i, f: randint(1, 1000))
seq2 = Sequence(lambda i, f: 1000)
io.input_writeln(seq1.get(1, 101), seq2.get(1, 398))
io.output_gen(code_path + 'standard.exe')
io.close()