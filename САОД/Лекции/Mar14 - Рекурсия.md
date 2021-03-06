Рекурсия
========
От лат. "возвращение" -- способ или метод органзации выч. процесса, при кот. процедура или функция в ходе выполнения оставлящих её операторов обращается сама к себе. 
Итерация -- способ организации обработки данных не приводя при этом рекурсии.
Рекурсивное определение данных возникает когда структура данных содержит вложенный объект, структурно аналогичный самому себе или ссылку на такой же объект.
```
struct elem_of_list
  {
    elem_of_list *next; //Ссылка на следующий элемент того же типа
    it data; //Данные
  }
```

У рекурсии, как и у математической индукции, есть **база** -- аргументы, для которых значения функции определены, и **шаг рекурсии** -- способ сведения задачи к более простым.
Количество одновременно выполняемых процедур называют **глубиной рекурсии**.

*Любой алгоритм, реализованный в рекурсивной форме, может быть переписан в итерационном виде, и наоборот.*

**Рекуррентная последовательность** -- последовательность, определённая через предыдущие значения. *Любую* рекуррентную формулу можно преобразовать в рекурсивный алгоритм. 
*С помощью метода мат-ой индукции доказывается верность алгоритма.*

Линейная рекурсия
-----------------
Рекурсия, при которой рекурсивные вызовы на любом рекурсивном срезе инициируют не более одного последующего вызова, называется **линейной**.
Это наиболее простой и часто встречающийся тип рекурсии.
*пример: вычисление факториала*
```
      | 1,        n<=1 //База
f(n)= |
      | n*f(n-1), n>1
```

Поворительная рекурсия
----------------------
Частный случай линейной рекурсии с отсутствующими предварительными или отложенными вычислениями азывается **повторительной рекурсией**.
*Напимер, функция:*
```
g3(n):= | 0 if n = 0
        | otherwise
        | | g3(n/2) if mod(n,2) = 0
        | | g3((n-1)/2)+1 otherwise
```
Эта рекурсия является повторительной. Здесь есть отложенные, но нет предварительных вычислений. Повторительная рекурсия достаточно просто преобразуется в цикл.

Каскадная(древовидная) рекурсия
-------------------------------
Этот тип рекурсии определяется как дополнительный к линейному.
Рекурсию называют **каскадной**, если она не является линейной.
Примеры каскадных рекурсий: непосредственная реализация рекурсивных вычислений чисел Фибоначчи и биномиальных коэффициентов, подсчёт количества разбиений натурального числа на сумму натуральных слагаемых.
Например, функция вычисления многочленов Чебышева:
```
T(n,x):= | if (n =0,1,x if n<=1
         | 2*x*T(n-1,x)-T(n-2,x( otherwise,
```
Функция T(n,x) реализована исходя из известной рекуррентной формулы `T_n+1(x)=2*x*T_n(x)-T_n-1(x)(n,1,2,...;T_0(x)=1,T_1*x)=x)`

1. Каждый вызов функции создаёт новый контекст(frame вызова).
2. Каждый frame содержит аргументы, локальные переменные и служебную инф-ию.
3. Максимально создаётся количество фреймов, равное глубине рекурсии.
4. Модификатор `static` указывает, что не нужно создавать новую копию переменной в новом фрейме, оставляя предыдущее значение.
*Также static сразу инициализирует переменную нулями*

Сложность рекурсивного алгоритма нахождения чисел Фибоначчи
-----------------------------------------------------------
```
fi=(sqrt(5)+1)/2
O(fi^n)
lim n->inf F_n/F_n-1 = fi
```

Сам код:
```
int Fibo(int n)
{
  static int c[MAXN];
  if n==0 return 0
  if n==1 return 1;
  if(c[n]>0) return c[n];
  c[n] = Fibo(n-1)+Fibo(n-2);
  return c[n];
}
```

Арифметические операции на разных процессорах
=============================================
```
____________________________________
|     | |int(32)  |    long(64)    |
|-----|-|---------|----------------|
|x86  |+|~1 такт  |    ~3 такта    |
|x64  |+|~1 такт  |    ~1 такт     |
|x86  |*|~3-4     |    ~15-50      |
|x64  |*|~3-4     |    ~4-5        |
------------------------------------

```
Алг-м Гаусса XIX век. O(n^2)
Алг-м Карацуба. O(n^log2(3))
```
N_1 = TX1 + y1
N_2 = Tx2 + y2
T = 100
37|58 37T+58
23|25 23T+25
-----
  |
N1*N2=T^2x1x2+T(x1y2+x2y1)+y1y2
```

Теорема о рекурсии
==================
**Рекурсия** -- разбиение задачи на подзачи с последующей консолидацией результата.
* Пусть а - кол-во подзадач.
* Размер каждой позадачи уменьшается в b раз и становится равным n/b с округлением вверх
* Сложность консолидации = O(n^d), где d = const, т.е. O() полиномиальна.
Тогда время работы такого алг-ма. выраженное рекуррентно, будет равно `T(n)=aT(up[n/b])+O(n^d)` *up[] - окр. вверх*
a>0, b>1, d>=0.
```
      | O(n^d),       d>loga(b)
T(n)= | O(n^d*log(n), d=logb(a)
      | O(n^logb(a),  d<logb(a)
```

```
0 1  ^ n * F0  =  Fn
1 1        F1     Fn+1
```
a^12 = a * a * ... * a
a^12 = a^6 * a^6
a^6  = a^3 * a^3
a^3  = a^2 * a
a^2  = a^a

a^9 = 1001
Если число нечёт. -- умножаем на само себя(битовый сдвиг влево), если чёт. -- пропускаем.
```
    | 1, x = 0
x^n=| (x^(n/2))^2, x!=0 + (n mod 2 = 0)
    | (x^(n-1)x, x!=0 + (n mod 2 !=0)
```
*Здесь "+" означает перевёрнутую U*

Косвенная(взаимная) рекурсия
============================
* Циклическая последовательность вызовов нескольких функций F1, F2, ..., Fk(процедур, алгоритмов) друг друга: F1 вызывает F2, F2 вызывает F3..., называют *косвенной или взаимной рекурсией**.
* Для целого неотрицательного n, обращаясь к взаимно-рекурсивным функциям g0(n) и g1(n), подсчитать и вернуть логическое значение, равное 1, если в двоичном представлении n имеется чётное число цифр "1", и 0 в противном случае.

Удалённая рекурсия
==================
* Рекурсия называется **удалённой**, если в теле функции при рекурсивных вызовах, в выражениях, являющизся фаткическими параметрами, снова встречаются рекурсивные вызовы этой функции.
* Подобный пример даёт нам классическая в теории рекурсии функция Аккермана:
```
ak(n,m) := | m+1,              n=0
           | ak(n-1,1),        m=0
           | ak(n-1,ak(n,m-1)), m!=0 & n!=0
```

