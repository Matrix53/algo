from cyaron import *

code_path = 'D:/Workspace/algo/Final-2/'

# big data
io = IO('1.in', '1.out')
io.input_writeln(1503500000, 199999, 199998)
io.input_writeln(1500000230, 1300045600)
seq = Sequence(lambda i, f: randint(1045600, 2000049999))
io.input_writeln(seq.get(1, 199999))
seq = Sequence(lambda i, f: randint(603500000, 800000229))
io.input_writeln(seq.get(1, 199999))
seq = Sequence(lambda i, f: randint(234561, 2000049999))
io.input_writeln(seq.get(1, 199998).sort())
seq = Sequence(lambda i, f: randint(700000229, 903500000))
io.input_writeln(seq.get(1, 199998).sort())
io.output_gen(code_path + 'standard.exe')
io.close()

# big data
io = IO('2.in', '2.out')
io.input_writeln(1503500000, 199999, 199998)
io.input_writeln(1500000230, 1500045600)
seq = Sequence(lambda i, f: randint(1045600, 1500049999))
io.input_writeln(seq.get(1, 199999))
seq = Sequence(lambda i, f: randint(700000229, 900000229))
io.input_writeln(seq.get(1, 199999))
seq = Sequence(lambda i, f: randint(234561, 1300099999))
io.input_writeln(seq.get(1, 199998).sort())
seq = Sequence(lambda i, f: randint(603500000, 803500000))
io.input_writeln(seq.get(1, 199998).sort())
io.output_gen(code_path + 'standard.exe')
io.close()

# hack data
io = IO('3.in', '3.out')
io.input_writeln(5, 3, 3)
io.input_writeln(4, 4)
io.input_writeln(1, 3, 1)
io.input_writeln(2, 3, 1)
io.input_writeln(2, 2, 5)
io.input_writeln(1, 2, 2)
io.output_gen(code_path + 'standard.exe')
io.close()