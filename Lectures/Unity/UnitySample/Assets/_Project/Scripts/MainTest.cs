using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[Serializable]
public class MyShape 
{
    public Transform Transform;

    public MeshFilter meshFilter;
    public MeshRenderer meshRederer;

    public Vector3 startPosition;
    public Mesh mesh;
    public Material material;
}

public class MainTest : MonoBehaviour
{
    public List<MyShape> shapes;

    UnityAttributeTest uat;
    
    void Start()
    {
        foreach(MyShape shape in shapes) 
        {
            if(shape == null) 
            {
                print("It's Null !!");
            }
            shape.meshFilter.mesh = shape.mesh;
            shape.meshRederer.material = shape.material;
            shape.Transform.position = shape.startPosition;
        }
    }


    void Update()
    {
        
    }
}
