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
        Debug.Log(stringList);//일반적인 참조타입은 유니티가 플레이될때 값을 주입을 해준다.
    }

    void Update()
    {

    }
}