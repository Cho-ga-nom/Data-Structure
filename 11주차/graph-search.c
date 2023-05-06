#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 10

typedef struct node
{
    int vertex;
    struct node *next;
}Node;

typedef struct graph
{
    Node *list[MAX_VERTEX];
    int vertex_num;   
}Graph;

void InitializeGraph(Graph *g);
void InsertVertex(Graph *g, int vertex);
void InsertEdge(Graph *g, int u, int v);
void PrintGraph(Graph *g);

int main()
{
    char command;
    int key;
    Graph *g = (Graph*)malloc(sizeof(Graph));

    do
    {
        printf("[----- [조수현]  [2018038084] -----]\n\n");

        printf("----------------------------------------------------------------\n");
        printf("                        Graph Searches               \n");
        printf("----------------------------------------------------------------\n");
        printf(" Initialize Graph        = z                                    \n");
        printf(" Insert Vertex           = v       Insert Edge               = e\n");
        printf(" Depth First Search      = d       Breath First Search       = b\n");
        printf(" Print Graph             = p       Quit                      = q\n");
        printf("----------------------------------------------------------------\n");

        printf("command : ");
        scanf(" %c", command);

        switch(command)
        {
            case 'z': case 'Z':
            InitializeGraph(g);
            break;
            case 'v': case 'V':
            printf("Your Key = ");
			scanf("%d", &key);
            InsertVertex(g, key);
            break;
            case 'd': case 'D':
            break;
            case 'p': case 'P':
            PrintGraph(g);
            break;
            case 'e': case 'E':
            InsertEdge(g, key, )
            break;
            case 'b': case 'B':
            break;
        }

    } while (command != 'q' && command != 'Q');
    
    free(g);
    return 1;
}

void InitializeGraph(Graph* g)
{
    int vertex;
    g->vertex_num = 0;

    for (vertex = 0; vertex < MAX_VERTEX; vertex++)
    {
        g->list[vertex] = NULL;
    }
}

void InsertVertex(Graph* g, int vertex)
{
    if ((g->vertex_num) + 1 > MAX_VERTEX)
    {
    printf("그래프 정점이 꽉 찼습니다.\n");
    return;
    }

    g->vertex_num++;
}

void InsertEdge(Graph* g, int u, int v)
{
    Node* node;

    if (u >= g->vertex_num || v >= g->vertex_num)
    {
        printf("존재하지 않는 정점입니다.\n");
        return;
    }

    node = (Node*)malloc(sizeof(Node));
    node->vertex = v;
    node->next = g->list[u];
    g->list[u] = node;
}

void PrintGraph(Graph *g)
{
    for(int i = 0; i < g->vertex_num; i++)
    {
        Node *g_print = g->list[i];
        printf("정점 %d의 인접 리스트 : ", i);

        while(g_print != NULL)
        {
            printf(" %d", g_print->vertex);
            g_print = g_print->next;
        }

        printf("\n");
    }
}