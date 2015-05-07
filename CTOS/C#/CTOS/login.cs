using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;
using System.Windows.Forms;

namespace CTOS
{
    public partial class login : Form
    {
        public static string strconn="Data Source=localhost\\SQLEXPRESS;";
        public static SqlConnection conn;
        public login()
        {
            InitializeComponent();
        }

        private void connection_Click(object sender, EventArgs e)
        {
            if (textBox1.Text == "")
            {
                MessageBox.Show("User name is Empty.","Error",MessageBoxButtons.OK,MessageBoxIcon.Error);
            }
            else if(textBox2.Text == "")
            {
                MessageBox.Show("Password is Empty.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else if(comboBox1.Text == "")
            {
                MessageBox.Show("Database is Empty.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else{
                try
                {
                    strconn += "Initial Catalog=" + comboBox1.Text+ ";User ID=" + textBox1.Text + ";Password=" + textBox2.Text + ";";
                    conn = new SqlConnection(strconn);
                    conn.Open();
                    main mainwin = new main();
                    mainwin.Show();
                    this.Hide();
                    mainwin.FormClosing += main_FormClosing;
                    textBox2.Text = "";
                }
                catch (SqlException ex)
                {
                    MessageBox.Show("Error:" + ex,"Error");
                }
            }
        }

        private void exit_Click(object sender, EventArgs e)
        {
            System.Environment.Exit(0);  
        }

        private void close_Click(object sender, EventArgs e)
        {
            conn.Close();
            MessageBox.Show("Connection Closed.");
        }

        private void main_FormClosing(object sender, FormClosingEventArgs e)
        {
            this.Show();
        }
    }
}
