void delete_duplicates(Node *head) { // Удаляет повторяемые элементы
   for (Node *p = head->next; p != NULL && p->next != NULL; p = p->next) {
      for (Node *q = p; q->next != NULL; q = q->next) {
         Node *t = q->next;
         if (p->data == t->data) {
            q->next = t->next;
            delete t;
            if (q->next == NULL) {
               break;
            }
         }
      }
   }
}


void swap_nodes(Node *head) {//Меняет местами 2 значения узлов
   Node *max_node = head->next, *min_node = head->next;
   for (Node *p = head->next; p->next != NULL; p = p->next) {
      if (p->next->data > max_node->data) {
         max_node = p->next;
      }
      if (p->next->data <= min_node->data) {
         min_node = p->next;
      }
   }
   int t;
   t = min_node->data;
   min_node->data = max_node->data;
   max_node->data = t;
}


void sort_list(Node *head) {//Сортируем методом пузырька
   bool f;
   for (Node *p = head->next; p->next != NULL; p = p->next) {
      f = 0;
      for (Node *q = p->next; q != NULL; q = q->next) {
         if (p->data > q->data) {
            int temp = p->data;
            p->data = q->data;
            q->data = temp;
            f = 1;
         }
      }
      if (f == 0) {
         return;
      }
   }
}


Node *merge_lists(Node *head1, Node *head2) { //
   Node *head = new Node;
   head->data = 1;
   head->next = NULL;
   Node *p = head1->next, *q = head2->next;
   Node *curr = head;
   while (p != NULL && q != NULL) {
      if (p->data < q->data) {
         curr->next = p;
         p = p->next;
      }
      else {
         curr->next = q;
         q = q->next;
      }
      curr = curr->next;
   }
   if (p != NULL) {
      curr->next = p;
   }
   if (q != NULL) {
      curr->next = q;
   }
   return head;
}


Node* copy_tree(Node* root){
   if(root == NULL){
      return NULL;
   }
   Node *new_root = new Node;
   new_root->data = root->data;
   new_root->left = copy_tree(root->left);
   new_root->right = copy_tree(root->right);
   return new_root;
}


int count_nodes(Node *root){
   if (root == NULL){
      return 0;
   }
   int c = 1;
   c += count_nodes(root->left) + count_nodes(root->right);
   return c;
}


int leaves_sum(Node *root){
   if (root == NULL){
      return 0;
   }
   int s = root->data;
   s += leaves_sum(root->left) + leaves_sum(root->right);
   return s;
}



