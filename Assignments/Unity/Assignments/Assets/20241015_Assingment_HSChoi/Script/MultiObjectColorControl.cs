using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[Serializable]
public class ColorControl
{
    public Renderer Renderer;
    public Color color;
}

public class MultiObjectColorControl : MonoBehaviour
{
    public List<ColorControl> ColorControl;

    
    public Color startColor;
    public Color endColor;

    void Start()
    {
        startColor = Color.blue;
        endColor = Color.magenta;

        for (int i = 0; i < ColorControl.Count; i++)
        {
            float t = (float)i / (ColorControl.Count-1);
            ColorControl[i].color = Color.Lerp(startColor, endColor, t);
            ColorControl[i].Renderer.material.color = ColorControl[i].color;
        }
    }
}