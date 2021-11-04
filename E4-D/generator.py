from cyaron import *

code_path = 'D:/Workspace/algo/BUAAOJ-X/Matrix53-E4-D/'

# small data
io = IO('1.in', '1.out')
io.input_writeln(100, 100)
for i in range(100):
    io.input_writeln(randint(1, 1000), randint(1, 100))
io.output_gen(code_path + 'standard.exe')
io.close()

# big data
for i in range(3):
    io = IO(str(i + 2) + '.in', str(i + 2) + '.out')
    io.input_writeln(1000, 100000)
    for j in range(1000):
        io.input_writeln(randint(1, 10000000), randint(1, 110000))
    io.output_gen(code_path + 'standard.exe')
    io.close()

# hack data
io = IO('5.in', '5.out')
io.input_writeln(1000, 100000)
for i in range(1000):
    io.input_writeln(10000000, 1)
io.output_gen(code_path + 'standard.exe')
io.close()
