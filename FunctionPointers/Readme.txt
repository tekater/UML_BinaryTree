//~Указатель на функцию

Имя функции является указателем на функцию, 
поскольку содержит адресс этой функции в памяти
и при вызове функции происходит переход по этому Аддресу.

Указатель на функцию можно сохранить в отдельной переменной
и через эту переменную вызывать функцию, это делается в том случае,
когда мы не знаем какую именно функцию мы хотим вызвать
и как правило указатель на функцию передаётся в другую функцию,
но для того чтобы вызвать функцию по указателю,
а не по имени сигнатура функции должна полностью совпадать
с сигнатурой указателя на эту функцию.

Сигнатура функции - это её прототип без возвращаемого значения,
то есть сигнатура в первую очередь показывает какие параметры принимает
функция.
void (*p_hello)() = hello; // void* - void pointer (указатель на 'void',
						   // может хранить адрес абсолютно любого типа)
	// при разыменовании void-pointer'a нужно обязательно преобразовывать его в целевой тип
	
