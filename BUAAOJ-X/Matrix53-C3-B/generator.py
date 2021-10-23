from cyaron import *

code_path = 'D:/Workspace/algo/BUAAOJ-X/Matrix53-C3-B/'

# small data
io = IO('1.in', '1.out')
io.input_writeln(10)
seq = Sequence(lambda i, f: randint(1, 10000))
io.input_writeln(seq.get(1, 10))
io.output_gen(code_path + 'standard.exe')
io.close()

# big data
for i in range(3):
    io = IO(str(i + 2) + '.in', str(i + 2) + '.out')
    io.input_writeln(10000)
    seq = Sequence(lambda i, f: randint(1, 100000))
    io.input_writeln(seq.get(1, 10000))
    io.output_gen(code_path + 'standard.exe')
    io.close()

# hack data
io = IO('5.in', '5.out')
io.input_writeln(10000)
seq = Sequence(lambda i, f: 10000000)
io.input_writeln(seq.get(1, 10000))
io.output_gen(code_path + 'standard.exe')
io.close()
