-- подключение библиотеки
rut = require("librut")

-- обращение происходит через .
timer = rut.TimerStart()
print(rut.Primes(1000000))
print(rut.TimerEnd(timer))