from cyaron import *
import random

code_path = 'D:/Workspace/algo/C4-E/'

# small data
io = IO('1.in', '1.out')
io.input_writeln(5000)
data = [i for i in range(1, 5001)]
random.shuffle(data)
io.input_writeln(data)
# Compare.program(code_path + 'standard.exe',
#                 input=io,
#                 std_program=code_path + 'compare.exe')
io.output_gen(code_path + 'standard.exe')
io.close()

# big data
io = IO('2.in', '2.out')
io.input_writeln(100000)
data = [i for i in range(1, 100001)]
random.shuffle(data)
io.input_writeln(data)
io.output_gen(code_path + 'standard.exe')
io.close()

# # hack data
# io = IO('3.in', '3.out')
# io.input_writeln(499)
# seq = Sequence(lambda i, f: 1000)
# io.input_writeln(seq.get(1, 499))
# io.output_gen(code_path + 'standard.exe')
# io.close()
