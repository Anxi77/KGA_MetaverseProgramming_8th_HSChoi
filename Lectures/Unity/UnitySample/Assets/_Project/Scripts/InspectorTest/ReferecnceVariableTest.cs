using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[Serializable]//C# Attribute : Ư����� (Ŭ���� , ���� , �Լ�)�� ���� ��Ÿ�����͸� ����
public class MyClass //�� Ŭ������ ���� �ٸ� ��������� �����ϱ� ���ؼ��� "����ȭ"�� �ʿ��ϴ�.
{
    public string name;
    public int id;
    public Sprite sprite;
}

public class ReferecnceVariableTest : MonoBehaviour
{
    public MyClass myClass;

    public List<MyClass> myClasses;

    void Start()
    {
        print(myClass);
        print(myClass.name);
    }


    void Update()
    {
        
    }
}
