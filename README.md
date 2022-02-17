# Поиск связей между понятиями в научной литературе

### Идея алгоритма

Один из вариантов решения поставленной задачи просто для каждой вершины запустить алгоритм поиска в ширину (bfs) и выяснить, достижимо ли множество вершин S1 (или S2 соответственно), а так как граф невзвешенный, то алгоритм bfs также позволит найти и расстояние до множества, если оно достижимо. Затем нужно будет просто отсортировать все вершины, из которых достижимы оба множества по возрастанию суммы расстояний.

Асимптотика времени работы такого алгоритма: O(N (N + M))

Однако заметим, что вместо этого мы можем искать все вершины достижимые из множества при помощи алгоритма bfs. Для этого достаточно сказать, что вершины множества - исходные (изначально лежат в очереди) и рассматривать рёбра графа в обратном направлении (так как мы будем искать достижимые из данного множества вершины). Тогда после запуска этого алгоритма для множества вершин мы будем знать вершины, из которых оно было достижимо в исходном графе и минимальное расстояние.
Потом нужно опять же отсортировать вершины по возрастанию суммы расстояний до множеств, но можно заметить, что сумма расстояний будет не больше 2N, то есть можно использовать сортировку подсчётом.

Асимптотика работы такого алгоритма: O(N + M)

У первого алгоритма есть очевидный недостаток, так как он будет работать медленнее. Однако, если нам нужно отвечать на много вопросов для какого-то фиксированного графа, то нам достаточно предподсчитать все расстояния лишь 1 раз, а затем можно будет легко искать расстояние от вершины до множества. Во втором же алгоритме мы сможем переиспользовать вычисленные значения, только если граф и какое-то из множеств остались такими же.
Также легко заметить, что этот алгоритм обобщается и на большее количество множеств.