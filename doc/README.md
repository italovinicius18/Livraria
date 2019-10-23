# Livraria do Vinícius

### Ítalo Vinícius Pereira Guimarães
### 18/0102656

## Compilar e executar

- Digite *make* no terminal no diretório do arquivo;

- Após o processo de compilação, digite *make run* para executar o programa;

O menu inicial aparecerá, e a partir daí já pode fazer seu registro, suas compras e descobrir o que recomendamos pra você.

### Modo venda

    Neste modo, o cliente fará o seu próprio registro, optando por ser sócio ou apenas cliente, se o CPF já tiver sido cadastrado anteriormente, ele irá direto ás compras. A compra funciona a partir da escolha da categoria a ser comprada e o código do livro que deseja, os quais serão listados para a consulta do cliente, os produtos escolhidos serão listados a cada compra e ficarão dentro de um carrinho até o cliente optar por concluir a compra, que então apresentará o valor total dos produtos, verificado se possuímos esta quantidade, a compra será efetuada e o valor será definido a partir do CPF cadastrado (20% de desconto para sócios) e dos produtos escolhidos.

### Modo estoque

    Neste modo, podemos adicionar novos livros, se a categoria não for identificada no estoque, esta categoria é criada,podemos adicionar a quantidade e o preço. Outra opção é mudar o valor de livros existentes no estoque.

### Modo recomenda

    Este modo não será efetivo para clientes não cadastados e que possuam nenhuma compra no histórico, caso contrário, será apresentado as categorias recomendadas por ordem de preferência, em cada categoria será listado os livros na ordem léxicográfica.

## Bibliotecas utilizadas

    - iostream;
    - fstream;
    - algorithm;
    - vector;
    - set;
    - string;
    - dirent;
    - system;
    - sys/types.