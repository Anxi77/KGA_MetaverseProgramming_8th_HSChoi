using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Test : MonoBehaviour
{

    private int count = 0;

    // Start is called before the first frame update
    void Start()
    {
        Debug.Log("Hello Unity");
        Debug.LogWarning("Hello Unity!");
        Debug.LogError("Heelo Unity!");
    }

    // Update is called once per frame
    void Update()
    {
        Debug.Log("Updating.");
        //Debug.Log(count++);
    }
}