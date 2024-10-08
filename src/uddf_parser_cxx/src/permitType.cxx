// Copyright (c) 2005-2023 Code Synthesis.
//
// This program was generated by CodeSynthesis XSD, an XML Schema to
// C++ data binding compiler.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
//
// In addition, as a special exception, Code Synthesis gives permission
// to link this program with the Xerces-C++ library (or with modified
// versions of Xerces-C++ that use the same license as Xerces-C++), and
// distribute linked combinations including the two. You must obey the GNU
// General Public License version 2 in all respects for all of the code
// used other than Xerces-C++. If you modify this copy of the program, you
// may extend this exception to your version of the program, but you are
// not obligated to do so. If you do not wish to do so, delete this
// exception statement from your version.
//
// Furthermore, Code Synthesis makes a special exception for the Free/Libre
// and Open Source Software (FLOSS) which is described in the accompanying
// FLOSSE file.
//

// Begin prologue.
//
//
// End prologue.

#include <xsd/cxx/pre.hxx>

#include "permitType.hxx"

#include "encapsulatedDateTimeType.hxx"

#include "notesType.hxx"

namespace streit
{
  // permitType
  //

  const permitType::name_type& permitType::
  name () const
  {
    return this->name_.get ();
  }

  permitType::name_type& permitType::
  name ()
  {
    return this->name_.get ();
  }

  void permitType::
  name (const name_type& x)
  {
    this->name_.set (x);
  }

  void permitType::
  name (::std::unique_ptr< name_type > x)
  {
    this->name_.set (std::move (x));
  }

  const permitType::aliasname_sequence& permitType::
  aliasname () const
  {
    return this->aliasname_;
  }

  permitType::aliasname_sequence& permitType::
  aliasname ()
  {
    return this->aliasname_;
  }

  void permitType::
  aliasname (const aliasname_sequence& s)
  {
    this->aliasname_ = s;
  }

  const permitType::region_optional& permitType::
  region () const
  {
    return this->region_;
  }

  permitType::region_optional& permitType::
  region ()
  {
    return this->region_;
  }

  void permitType::
  region (const region_type& x)
  {
    this->region_.set (x);
  }

  void permitType::
  region (const region_optional& x)
  {
    this->region_ = x;
  }

  void permitType::
  region (::std::unique_ptr< region_type > x)
  {
    this->region_.set (std::move (x));
  }

  const permitType::issuedate_optional& permitType::
  issuedate () const
  {
    return this->issuedate_;
  }

  permitType::issuedate_optional& permitType::
  issuedate ()
  {
    return this->issuedate_;
  }

  void permitType::
  issuedate (const issuedate_type& x)
  {
    this->issuedate_.set (x);
  }

  void permitType::
  issuedate (const issuedate_optional& x)
  {
    this->issuedate_ = x;
  }

  void permitType::
  issuedate (::std::unique_ptr< issuedate_type > x)
  {
    this->issuedate_.set (std::move (x));
  }

  const permitType::validdate_optional& permitType::
  validdate () const
  {
    return this->validdate_;
  }

  permitType::validdate_optional& permitType::
  validdate ()
  {
    return this->validdate_;
  }

  void permitType::
  validdate (const validdate_type& x)
  {
    this->validdate_.set (x);
  }

  void permitType::
  validdate (const validdate_optional& x)
  {
    this->validdate_ = x;
  }

  void permitType::
  validdate (::std::unique_ptr< validdate_type > x)
  {
    this->validdate_.set (std::move (x));
  }

  const permitType::notes_optional& permitType::
  notes () const
  {
    return this->notes_;
  }

  permitType::notes_optional& permitType::
  notes ()
  {
    return this->notes_;
  }

  void permitType::
  notes (const notes_type& x)
  {
    this->notes_.set (x);
  }

  void permitType::
  notes (const notes_optional& x)
  {
    this->notes_ = x;
  }

  void permitType::
  notes (::std::unique_ptr< notes_type > x)
  {
    this->notes_.set (std::move (x));
  }
}

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace streit
{
  // permitType
  //

  permitType::
  permitType (const name_type& name)
  : ::xml_schema::type (),
    name_ (name, this),
    aliasname_ (this),
    region_ (this),
    issuedate_ (this),
    validdate_ (this),
    notes_ (this)
  {
  }

  permitType::
  permitType (const permitType& x,
              ::xml_schema::flags f,
              ::xml_schema::container* c)
  : ::xml_schema::type (x, f, c),
    name_ (x.name_, f, this),
    aliasname_ (x.aliasname_, f, this),
    region_ (x.region_, f, this),
    issuedate_ (x.issuedate_, f, this),
    validdate_ (x.validdate_, f, this),
    notes_ (x.notes_, f, this)
  {
  }

  permitType::
  permitType (const ::xercesc::DOMElement& e,
              ::xml_schema::flags f,
              ::xml_schema::container* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    name_ (this),
    aliasname_ (this),
    region_ (this),
    issuedate_ (this),
    validdate_ (this),
    notes_ (this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e, true, false, false);
      this->parse (p, f);
    }
  }

  void permitType::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::flags f)
  {
    for (; p.more_content (); p.next_content (false))
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      // name
      //
      if (n.name () == "name" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        ::std::unique_ptr< name_type > r (
          name_traits::create (i, f, this));

        if (!name_.present ())
        {
          this->name_.set (::std::move (r));
          continue;
        }
      }

      // aliasname
      //
      if (n.name () == "aliasname" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        ::std::unique_ptr< aliasname_type > r (
          aliasname_traits::create (i, f, this));

        this->aliasname_.push_back (::std::move (r));
        continue;
      }

      // region
      //
      if (n.name () == "region" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        ::std::unique_ptr< region_type > r (
          region_traits::create (i, f, this));

        if (!this->region_)
        {
          this->region_.set (::std::move (r));
          continue;
        }
      }

      // issuedate
      //
      if (n.name () == "issuedate" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        ::std::unique_ptr< issuedate_type > r (
          issuedate_traits::create (i, f, this));

        if (!this->issuedate_)
        {
          this->issuedate_.set (::std::move (r));
          continue;
        }
      }

      // validdate
      //
      if (n.name () == "validdate" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        ::std::unique_ptr< validdate_type > r (
          validdate_traits::create (i, f, this));

        if (!this->validdate_)
        {
          this->validdate_.set (::std::move (r));
          continue;
        }
      }

      // notes
      //
      if (n.name () == "notes" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        ::std::unique_ptr< notes_type > r (
          notes_traits::create (i, f, this));

        if (!this->notes_)
        {
          this->notes_.set (::std::move (r));
          continue;
        }
      }

      break;
    }

    if (!name_.present ())
    {
      throw ::xsd::cxx::tree::expected_element< char > (
        "name",
        "http://www.streit.cc/uddf/3.2/");
    }
  }

  permitType* permitType::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class permitType (*this, f, c);
  }

  permitType& permitType::
  operator= (const permitType& x)
  {
    if (this != &x)
    {
      static_cast< ::xml_schema::type& > (*this) = x;
      this->name_ = x.name_;
      this->aliasname_ = x.aliasname_;
      this->region_ = x.region_;
      this->issuedate_ = x.issuedate_;
      this->validdate_ = x.validdate_;
      this->notes_ = x.notes_;
    }

    return *this;
  }

  permitType::
  ~permitType ()
  {
  }
}

#include <ostream>

namespace streit
{
  ::std::ostream&
  operator<< (::std::ostream& o, const permitType& i)
  {
    o << ::std::endl << "name: " << i.name ();
    for (permitType::aliasname_const_iterator
         b (i.aliasname ().begin ()), e (i.aliasname ().end ());
         b != e; ++b)
    {
      o << ::std::endl << "aliasname: " << *b;
    }

    if (i.region ())
    {
      o << ::std::endl << "region: " << *i.region ();
    }

    if (i.issuedate ())
    {
      o << ::std::endl << "issuedate: " << *i.issuedate ();
    }

    if (i.validdate ())
    {
      o << ::std::endl << "validdate: " << *i.validdate ();
    }

    if (i.notes ())
    {
      o << ::std::endl << "notes: " << *i.notes ();
    }

    return o;
  }
}

#include <istream>
#include <xsd/cxx/xml/sax/std-input-source.hxx>
#include <xsd/cxx/tree/error-handler.hxx>

namespace streit
{
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

