from cyaron import *

code_path = 'D:/Workspace/algo/Final-1/'

# odd number
io = IO('1.in', '1.out')
s = String.random(40000, charset="0123456789")
s += '0' * 101
s += String.random(40000, charset="0123456789")
io.input_writeln(s)
io.output_gen(code_path + 'standard.exe')
io.close()

# odd number
io = IO('2.in', '2.out')
s = String.random(45000, charset="0123456789")
s += String.random(40001, charset="0123456789")
io.input_writeln(s)
io.output_gen(code_path + 'standard.exe')
io.close()

# even number
io = IO('3.in', '3.out')
s = String.random(44000, charset="0123456789")
s += '0' * 1000
s += String.random(44000, charset="0123456789")
io.input_writeln(s)
io.output_gen(code_path + 'standard.exe')
io.close()

# even number
io = IO('4.in', '4.out')
s = String.random(44005, charset="0123456789")
s += String.random(44005, charset="0123456789")
io.input_writeln(s)
io.output_gen(code_path + 'standard.exe')
io.close()
