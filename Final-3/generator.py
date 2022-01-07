from cyaron import *

code_path = 'D:/Workspace/algo/Final-3/'

# big data
io = IO('1.in', '1.out')
io.input_writeln(200, 200)
seq = Sequence(lambda i, f: randint(0, 20000))
for i in range(200):
    io.input_writeln(seq.get(1 + 200 * i, 201 + 200 * i))
io.output_gen(code_path + 'standard.exe')
io.close()

# big data
io = IO('2.in', '2.out')
io.input_writeln(200, 200)
seq = Sequence(lambda i, f: randint(0, 20000))
for i in range(200):
    io.input_writeln(seq.get(1 + 200 * i, 201 + 200 * i))
io.output_gen(code_path + 'standard.exe')
io.close()

# big data
io = IO('3.in', '3.out')
io.input_writeln(200, 200)
seq = Sequence(lambda i, f: randint(0, 20000))
for i in range(200):
    io.input_writeln(seq.get(1 + 200 * i, 201 + 200 * i))
io.output_gen(code_path + 'standard.exe')
io.close()

# big data
io = IO('4.in', '4.out')
io.input_writeln(200, 200)
seq = Sequence(lambda i, f: randint(0, 20000))
for i in range(200):
    io.input_writeln(seq.get(1 + 200 * i, 201 + 200 * i))
io.output_gen(code_path + 'standard.exe')
io.close()

# big data
io = IO('5.in', '5.out')
io.input_writeln(200, 200)
seq = Sequence(lambda i, f: randint(0, 20000))
for i in range(200):
    io.input_writeln(seq.get(1 + 200 * i, 201 + 200 * i))
io.output_gen(code_path + 'standard.exe')
io.close()