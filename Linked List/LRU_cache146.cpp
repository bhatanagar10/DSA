#include <bits/stdc++.h>
  #include <complex>
  #include <queue>
  #include <set>
  #include <unordered_set>
  #include <list>
  #include <chrono>
  #include <random>
  #include <iostream>
  #include <algorithm>
  #include <cmath>
  #include <string>
  #include <vector>
  #include <map>
  #include <unordered_map>
  #include <stack>
  #include <iomanip>
  #include <fstream>
  #include <typeinfo>

  using namespace std;

  struct Node{
  public:
    int key;
    int value;
    Node* next;
    Node* prev;
    Node(int key , int value) : key(key) , value(value), next(nullptr) ,prev(nullptr){}

  };

  class LRUCache {

    unordered_map<int,Node*>mp;
    int capacity;
    Node* head, *tail;

    public:
    LRUCache(int capacity) {
      this->capacity = capacity;
      head = new Node(0 , 0);
      tail = new Node(0 , 0);
      head->next = tail;
      tail->prev = head;
    }

    void add(Node* node ){
      mp[node->key] = node;
      if(head->next == tail && tail->prev == head){
        head->next = node;
        tail->prev = node;
        node->prev = head;
        node->next = tail;
      }
      else{
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
      }
    }
    void remove(Node * node){
      mp.erase(node->key);
      if(node == tail->prev){
        tail->prev = tail->prev->prev;
        tail->prev->next = tail;
      }
      else{
        node->prev->next = node->next;
        node->next->prev = node->prev;
      }

    }

    int get(int key) {

      if(mp.find(key) == mp.end()){
        return -1;
      }
      Node*t = mp.at(key);
      remove(t);
      add(t);
      return mp.at(key)->value;
    }

    void put(int key, int value) {
      if(mp.find(key) != mp.end()){
        remove(mp.at(key));
      }

      if(mp.size() == capacity){
          remove(tail->prev);
      }
      add(new Node(key , value));

    }
};
    // O(1) & O(N)
    /*
    int get(int key) {
      if(mp.find(key) == mp.end()){
        return -1;
      }
      else{
        mp.at(key).second = ++count;
        return mp.at(key).first;
      }
    }

    void put(int key, int value) {

      if(mp.size()< capacity){
        mp[key] = make_pair(value , ++count);
      }
      else{
        if(mp.find(key) != mp.end()){
          mp[key] = make_pair(value , ++count);
        }
        else{
            pair<int,int>lru=make_pair(0,INT_MAX);
            for(auto i : mp){
              if  (i.second.second < lru.second){
                lru.second = i.second.second;
                  lru.first = i.first;
                  }
                }
                mp.erase(lru.first);
                mp[key] =make_pair(value , ++count);
            }
        }
    }
    */

  int code(){
    //code here
    LRUCache* obj = new LRUCache(1);

    cout<<obj->get(6)<<" ";
    cout<<obj->get(8)<<" ";
    obj->put(12,1);
    cout<<obj->get(2)<<" ";
    obj->put(15,11);
    obj->put(5,2);
    obj->put(1,15);
    obj->put(4,2);
    cout<<obj->get(5)<<" ";
    obj->put(15,15);

    return 0;
  }

  int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    code();
    return 0;
  }
