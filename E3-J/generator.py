from cyaron import *

code_path = 'D:/Workspace/algo/BUAAOJ-X/Matrix53-5/'

# # small data
# for i in range(5):
#     io = IO(str(i + 1) + '.in', str(i + 1) + '.out')
#     io.input_writeln(10)
#     seq = Sequence(lambda i, f: randint(1, 100))
#     io.input_writeln(seq.get(0, 10))
#     io.input_writeln(seq.get(11, 21))
#     Compare.program(code_path + 'standard.exe',
#                     input=io,
#                     std_program=code_path + 'compare.exe')
#     io.close()

# big data
for i in range(5):
    io = IO(str(i + 1) + '.in', str(i + 1) + '.out')
    io.input_writeln(100000)
    seq = Sequence(lambda i, f: randint(1, 10000000))
    io.input_writeln(seq.get(0, 100000))
    io.input_writeln(seq.get(100001, 200001))
    io.output_gen(code_path + 'standard.exe')
    io.close()

# # hack data
# io = IO('5.in', '5.out')
# io.input_writeln(3500)
# seq = Sequence(lambda i, f: 9999999)
# io.input_writeln(seq.get(0, 3499))
# io.output_gen(code_path + 'standard.exe')
# io.close()
