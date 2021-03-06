from cyaron import *

code_path = 'D:/Workspace/algo/E2-I/'

# small data
io = IO('1.in', '1.out')
io.input_writeln(500)
seq = Sequence(lambda i, f: randint(1, 10000000))
io.input_writeln(seq.get(0, 499))
Compare.program(code_path + 'standard.exe',
                input=io,
                std_program=code_path + 'compare.exe')
io.output_gen(code_path + 'standard.exe')
io.close()

# big data
for i in range(3):
    io = IO(str(i + 2) + '.in', str(i + 2) + '.out')
    io.input_writeln(3500)
    seq = Sequence(lambda i, f: randint(1, 10000000))
    io.input_writeln(seq.get(0, 3499))
    io.output_gen(code_path + 'standard.exe')
    io.close()

# hack data
io = IO('5.in', '5.out')
io.input_writeln(3500)
seq = Sequence(lambda i, f: 9999999)
io.input_writeln(seq.get(0, 3499))
io.output_gen(code_path + 'standard.exe')
io.close()