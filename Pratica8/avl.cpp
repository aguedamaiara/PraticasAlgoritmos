/*
 * avl.cpp
 *
 *  Created on: 3 de nov de 2017
 *      Author: ramide
 */

#include "avl.h"
#include <iostream>

using namespace std;

// Realiza a inser�o como na BST, mas na volta da recurs�o,
// testa se est� balanceada, e se n�o estiver, balanceia
BinaryTree::Node *AVLTree::insert(BinaryTree::Node *root, int key) {
  root = BinaryTree::insert(root, key);

  if (!balanced(root))
    root = rebalance(root);

  return root;
}

// Realiza a remo�o como na BST, mas na volta da recurs�o,
// testa se est� balanceada, e se n�o estiver, balanceia
BinaryTree::Node *AVLTree::remove(BinaryTree::Node *root, int key) {
  if (root == NULL)
    return NULL;

  root = BinaryTree::remove(root, key);

  if (root != NULL && !balanced(root))
    root = rebalance(root);

  return root;
}

// Implementa�o de removeMax(), usada pela remo�o.
BinaryTree::Node *AVLTree::removeMax(BinaryTree::Node *root, int &max) {

  root = BinaryTree::removeMax(root, max);

  if (root != NULL && !balanced(root))
    root = rebalance(root);

  return root;
}

// Faz o balanceamento da �rvore no ponto root
// Deve ser feita chamada na volta da recurs�o (subindo a �rvore)
// no primeiro n� que estiver desbalanceado
BinaryTree::Node *AVLTree::rebalance(Node *root) {
  ASSERT(!balanced(root), "Already balanced!");

  if (leftHeavy(root)) { // Desbalanceada � esquerda de root (L*)

    if (rightHeavy(
            root->left)) // Desbalancada � esquerda/direita (LR) -> duas rota�es
      root->left = rotateLeft(root->left); // 1a rota�o -> LL

    root = rotateRight(root); // LL -> 2a rota�o (ou �nica, se j� fosse LL)

  } else { // Desbalanceada � direita de root (R*)

    if (leftHeavy(root->right)) // Desbalancada � direita/esquerda (RL) -> duas
                                // rota�es
      root->right = rotateRight(root->right); // 1a rota�o -> RR

    root = rotateLeft(root); // RR -> 2a rota�o (ou �nica, se j� fosse RR)
  }

  ASSERT(balanced(root), "Rebalance failed!");
  return root;
}

int AVLTree::validate(Node *root, int &min, int &max) {
  int valid = BinaryTree::validate(root, min, max);

  return valid && balanced(root);
}

// Realiza a rota�o a esquerda sobre "root" retornando a nova raiz
BinaryTree::Node *AVLTree::rotateLeft(Node *root) {
  if (root == nullptr || root->right == nullptr)
    return root;

  Node *pivot = root->right;
  root->right = pivot->left;
  pivot->left = root;

  updateH(root);
  updateH(pivot);

  return pivot;
}

// Realiza a rota�o a direita sobre "root" retornando a nova raiz
BinaryTree::Node *AVLTree::rotateRight(Node *root) {
  if (root == nullptr || root->left == nullptr) return root;

    Node *pivot = root->left;
    root->left = pivot->right;
    pivot->right = root;

    updateH(root);
    updateH(pivot);

    return pivot;
}

// Exibi�o da �rvore AVL
void AVLTree::show(Node *root) {
  if (root == nullptr) return;

    show(root->left);
    cout << "(" << root->key << ", " << root->height << ", " << BF(root) << ") ";
    show(root->right);
}