using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;



public class CollectionVarialbeTest : MonoBehaviour
{


    public string[] stringArray;
    public List<string> stringList;
    public LinkedList<string> stringLList;
    public Queue<string> stringQueue;
    public Stack<string> stringStack;
    public Dictionary<string, string> stringDic;

    void Start()
    {
        foreach (string str in stringArray)
        {
            Debug.Log(str);
        }
        Debug.Log(stringLList);
        Debug.Log(stringList);//�Ϲ����� ����Ÿ���� ����Ƽ�� �÷��̵ɶ� ���� ������ ���ش�.
    }

    void Update()
    {

    }
}