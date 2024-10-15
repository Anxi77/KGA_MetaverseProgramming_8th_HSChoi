using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ColorTest : MonoBehaviour
{
    public Color targetColor;

    public Renderer targetRenderer;

    void Start()
    {
        targetRenderer.material.color = targetColor;
    }

    void Update()
    {
        
    }
}
