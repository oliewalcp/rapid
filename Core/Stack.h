#ifndef STACK_H
#define STACK_H

#include "Core/TLNode.h"
#include "Core/TypeTraits.h"
#include "Core/Version.h"
#include <initializer_list>

namespace rapid
{
template<typename T>
class Stack
{
public:
    using ValueType = T;
    using Pointer = ValueType*;
    using Reference = ValueType&;
    using ConstReference = const ValueType &;
    using RvalueReference = ValueType&&;
    using SizeType = size_type;
private:
    struct Node
    {
        Node *Next;
        NodeBase<ValueType> *Data;
        Node(ConstReference arg, Node *n = nullptr)
            : Next(n), Data(new NodeBase<ValueType>(arg)) {}
        ~Node() { delete Data; }
    };

    SizeType _M_size = 0;
    Node *_M_top = nullptr;

    void _F_push(ConstReference arg)
    {
        _M_top = _F_construct_node(arg, _M_top);
        _F_add_size(1);
    }
    void _F_exchange(const Stack &s)
    {
        Node *temp = _M_top;
        SizeType st = _M_size;
        _M_top = s._M_top;
        _M_size = s._M_size;
        s._M_top = temp;
        s._M_size = st;
    }
    Node* _F_construct_node(ConstReference arg, Node *next = nullptr)
    { return new Node(arg, next); }

    void _F_add_size(SizeType arg)
    { _M_size += arg; }
public:
    Stack() { }
    Stack(const Stack &arg)
    {
        Node *n = arg._M_top;
        while(n != nullptr)
        {
            push(n->Data->const_ref_content());
            n = n->Next;
        }
    }
    Stack(std::initializer_list<ValueType> arg_list)
    {
        for(auto it = arg_list.begin(); it != arg_list.end(); ++it)
        { push(*it); }
    }
    Stack(Stack &&arg)
    { _F_exchange(forward<Stack>(arg)); }

    ~Stack()
    { clear(); }

    SizeType size() const
    { return _M_size; }

    bool empty() const
    { return size() == 0; }

    void push(ConstReference arg)
    { _F_push(arg); }

    void push(RvalueReference arg)
    { _F_push(forward<ValueType>(arg)); }

    ValueType top() const
    { return _M_top != nullptr ? _M_top->Data->content() : NodeBase<ValueType>().content(); }

    void pop()
    {
        if(empty()) return;
        Node *n = _M_top;
        _M_top = _M_top->Next;
        delete n;
        _F_add_size(-1);
    }
    void clear()
    {
        while(!empty())
        { pop(); }
    }

    void swap(const Stack &s)
    { _F_exchange(s); }
    void swap(Stack &&s)
    { _F_exchange(forward<Stack>(s)); }
};

};

#endif // STACK_H
