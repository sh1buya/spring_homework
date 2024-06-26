# Составляющие ДП (формула пересчета, порядок, база, где ответ)Составляющие ДП (формула пересчета, порядок, база, где ответ)

**Динамическое программирование** — это когда у нас есть задача, которую непонятно как решать, и мы разбиваем ее на меньшие задачи, которые тоже непонятно как решать.

Чтобы успешно решить задачу динамикой нужно:
1) Состояние динамики: параметр(ы), однозначно задающие подзадачу.
2) Значения начальных состояний.
3) Переходы между состояниями: формула пересчёта.
4) Порядок пересчёта.
5) Положение ответа на задачу: иногда это сумма или, например, максимум из значений нескольких состояний.

## Порядок пересчёта

Существует три порядка пересчёта:
**1)** Прямой порядок:
Состояния последовательно пересчитывается исходя из уже посчитанных.![](https://habrastorage.org/r/w1560/storage3/f1f/36c/875/f1f36c87585e05a9beb692324fa6b72e.png)

**2)** Обратный порядок:
Обновляются все состояния, зависящие от текущего состоянияю.![](https://habrastorage.org/r/w1560/storage3/0ae/3a1/bf4/0ae3a1bf4aed4161e8375305693cbf69.png)

**3)** Ленивая динамика:
Рекурсивная мемоизированная функция пересчёта динамики. Это что-то вроде поиска в глубину по ацикличному графу состояний, где рёбра — это зависимости между ними.
![](https://habrastorage.org/r/w1560/storage3/045/d67/fbe/045d67fbe78f0d724d75dd89a352cfe2.png)

**Прямой порядок:**
```python
fib[1] = 1  # Начальные значения
fib[2] = 1  # Начальные значения
for i in range(3, n + 1):
    fib[i] = fib[i - 1] + fib[i - 2]  # Пересчёт состояния i
```

**Обратный порядок:**
```python
fib[1] = 1  # Начальные значения
for i in range(1, n):
    fib[i + 1] += fib[i]  # Обновление состояния i + 1
    fib[i + 2] += fib[i]  # Обновление состояния i + 2
```

**Ленивая динамика:**
```python
def get_fib(i):
    if (i <= 2):  # Начальные значения
        return 1
    if (fib[i] != -1):  # Ленивость
        return fib[i]
    fib[i] = get_fib(i - 1) + get_fib(i - 2)  # Пересчёт
    return fib[i]
```