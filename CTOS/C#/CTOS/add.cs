using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CTOS
{
    public partial class add : Form
    {

        SqlConnection conn = new SqlConnection(login.strconn);
        SqlCommand cmd;
        public add()
        {
            InitializeComponent();
        }

        private void addData_Click(object sender, EventArgs e)
        {
            conn.Open();
            string sql = @"INSERT Loop(id,name,gender,job,phone,address,marriage,salary,age)"; 
            sql += "VALUES("+Int32.Parse(textBox1.Text)+",'"+textBox2.Text.ToString()+"','"+textBox3.Text.ToString()+"','"+textBox4.Text.ToString()
                + "','" + textBox5.Text.ToString() + "','" + textBox6.Text.ToString() + "','" + textBox7.Text.ToString()
                + "','" + Convert.ToDecimal(textBox8.Text)+"',"+Int32.Parse(textBox9.Text)+")";
            cmd = new SqlCommand(sql, conn);
            cmd.ExecuteNonQuery();
        }

        private void cancelData_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
